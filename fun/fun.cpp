// ascii_art.cpp
// 依赖：OpenCV (测试过 opencv4)，编译示例见下方
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;

// 默认字符集：从“深”到“浅”
// 你可以把它换成更多层次的 unicode 块字符或全角字符以提升细节
const string DEFAULT_CHARSET = "@%#*+=-:. ";

// 一个更精细的 Unicode 字符集（终端支持 UTF-8 时效果更好）
// const string UNICODE_CHARSET = "█▓▒░ .";

static inline int clampi(int v, int a, int b) { return v < a ? a : (v > b ? b : v); }

string image_to_ascii(const Mat& src, int outWidth,
                      const string& charset = DEFAULT_CHARSET,
                      bool invert = false,
                      bool edge_enhance = true,
                      double contrast = 1.0, double brightness = 0.0,
                      double char_aspect = 2.0) {
    // char_aspect: 字符高度/宽度 比率（一般终端字符高约为宽的2倍）
    // 将输出宽度映射到高度
    int inW = src.cols, inH = src.rows;
    if(outWidth <= 0) outWidth = 80;
    double scale = (double)outWidth / (double)inW;
    // 输出字符高度应考虑字符的纵横比
    int outHeight = max(1, (int)round(inH * scale / char_aspect));

    Mat gray;
    if(src.channels() == 3) cvtColor(src, gray, COLOR_BGR2GRAY);
    else gray = src.clone();

    // 调整大小（使用双线性插值）
    Mat small;
    resize(gray, small, Size(outWidth, outHeight), 0, 0, INTER_LINEAR);

    // 可选：对比度和亮度调整
    if (contrast != 1.0 || brightness != 0.0) {
        small.convertTo(small, -1, contrast, brightness);
    }

    // 可选：边缘检测（Sobel）并叠加到亮度作为权重增强
    Mat edge;
    if (edge_enhance) {
        Mat gx, gy;
        Sobel(small, gx, CV_16S, 1, 0, 3);
        Sobel(small, gy, CV_16S, 0, 1, 3);
        Mat mag;
        magnitude(gx, gy, mag);
        // 归一化到 0-255
        double mn, mx;
        minMaxLoc(mag, &mn, &mx);
        if (mx < 1e-6) mx = 1.0;
        mag.convertTo(edge, CV_8U, 255.0 / mx);
    }

    // 构建 ascii 文本
    string out;
    int charsetLen = (int)charset.size();
    for (int y = 0; y < small.rows; ++y) {
        for (int x = 0; x < small.cols; ++x) {
            int lum = small.at<uchar>(y, x);
            if (edge_enhance) {
                int e = edge.at<uchar>(y, x);
                // 将边缘信息混合入亮度：降低亮度（更暗）以产生更粗的字符
                // 比例可以调节
                double alpha = 0.7; // 边缘权重（0..1），可调
                lum = clampi((int)round((1.0 - alpha) * lum + alpha * (255 - e)), 0, 255);
            }
            if (invert) lum = 255 - lum;
            // 将 lum (0..255) 映射到字符集中（深->浅）
            double t = lum / 255.0;
            int idx = (int)floor(t * (charsetLen - 1e-9));
            // 0-->最深字符, charset[0] 为最“密”
            // 若需要反过来则调整
            char ch = charset[idx];
            out.push_back(ch);
        }
        out.push_back('\n');
    }
    return out;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <image_path> [options]\n"
             << "Options:\n"
             << "  -w <width>            output width in chars (default 80)\n"
             << "  -o <out.txt>          write output to file (default prints to stdout)\n"
             << "  -c <charset>          charset string from dark->light (no spaces recommended)\n"
             << "  --invert              invert brightness mapping\n"
             << "  --noedge              disable edge enhancement\n"
             << "  --contrast <val>      contrast multiplier (default 1.0)\n"
             << "  --brightness <val>    brightness offset (default 0.0)\n             ";
        return 1;
    }

    string image_path = argv[1];
    int width = 100;
    string out_file = "";
    string charset = DEFAULT_CHARSET;
    bool invert = false;
    bool edge_enhance = true;
    double contrast = 1.0, brightness = 0.0;
    double char_aspect = 2.0;

    for (int i = 2; i < argc; ++i) {
        string a = argv[i];
        if (a == "-w" && i + 1 < argc) { width = stoi(argv[++i]); }
        else if (a == "-o" && i + 1 < argc) { out_file = argv[++i]; }
        else if (a == "-c" && i + 1 < argc) { charset = argv[++i]; }
        else if (a == "--invert") { invert = true; }
        else if (a == "--noedge") { edge_enhance = false; }
        else if (a == "--contrast" && i + 1 < argc) { contrast = stod(argv[++i]); }
        else if (a == "--brightness" && i + 1 < argc) { brightness = stod(argv[++i]); }
        else if (a == "--char_aspect" && i + 1 < argc) { char_aspect = stod(argv[++i]); }
        else {
            cerr << "Unknown option: " << a << "\n";
        }
    }

    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty()) {
        cerr << "Failed to read image: " << image_path << "\n";
        return 2;
    }

    // 可先做高斯模糊去噪（可选）
    // GaussianBlur(img, img, Size(3,3), 0);

    // 生成 ASCII
    string ascii = image_to_ascii(img, width, charset, invert, edge_enhance, contrast, brightness, char_aspect);

    if (!out_file.empty()) {
        ofstream fout(out_file, ios::out);
        fout << ascii;
        fout.close();
        cout << "Written to " << out_file << "\n";
    } else {
        // 输出到 stdout（确保终端使用等宽字体）
        cout << ascii;
    }

    return 0;
}
