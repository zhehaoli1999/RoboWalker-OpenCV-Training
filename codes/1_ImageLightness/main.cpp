#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha; /**< 控制对比度 */
int beta;  /**< 控制亮度 */

int main( int argc, char** argv )
{
    /// 读入用户提供的图像
    Mat image = imread( "../../data/lena.png" );
    if(image.empty())
    {
        printf("image read error. Check the path of image. \n");
        exit(1);
    }
    Mat new_image = Mat::zeros( image.size(), image.type() );

    /// 初始化
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "* Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    cout << "* Enter the beta value [0-100]: ";
    cin >> beta;

    /// 执行运算 new_image(i,j) = alpha*image(i,j) + beta
    for( int y = 0; y < image.rows; y++ )
    {
        for( int x = 0; x < image.cols; x++ )
        {
            for( int c = 0; c < 3; c++ )
            {
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    /// 创建窗口
    namedWindow("Original Image", 1);
    namedWindow("New Image", 1);

    /// 显示图像
    imshow("Original Image", image);
    imshow("New Image", new_image);

    /// 等待用户按键
    waitKey();
    return 0;
}

