#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int sobel_x[3][3];
int sobel_y[3][3];

int main()
{
    // load an image
    String imglo ="/Users/calvinlee/opencvpjt_img/opencvpjt_img/what.jpg";
    Mat img = imread(imglo, 0); //default image channel is 3// 0 => grayscale => channel 1
    Mat newimg = Mat::zeros(img.size(), img.type());
    if (newimg.type() == img.type() )
    {
        cout<< "YESH"<<endl;
    }
    
    // asigning values to sobel x direction
    sobel_x[0][0] = -1; sobel_x[0][1] = 0; sobel_x[0][2] =1;
    sobel_x[1][0] = -2; sobel_x[1][1] = 0; sobel_x[1][2] =2;
    sobel_x[2][0] = -1; sobel_x[2][1] = 0; sobel_x[2][2] =1;
    // asigning values to sobel y direction
    sobel_y[0][0] = -1; sobel_y[0][1] = -2; sobel_y[0][2] = -1;
    sobel_y[1][0] = 0; sobel_y[1][1] = 0; sobel_y[1][2] = 0;
    sobel_y[2][0] = 1; sobel_y[2][1] = 2; sobel_y[2][2] = 1;
    
    //cout<<img.cols<<endl; //rows = 420, cols = 760
    cout<<"(0,0) Original value is "<<(int)img.at<uchar>(0,0)<<endl; //retrive the value in (0,0)
    
    for (int j = 0; j<img.rows-2; j++)
     {
     for (int i = 0; i<img.cols-2; i++)
     {
         int pixval_x =
         (sobel_x[0][0] * (int)img.at<uchar>(j,i)) + (sobel_x[0][1] * (int)img.at<uchar>(j+1,i)) + (sobel_x[0][2] * (int)img.at<uchar>(j+2,i)) +
         (sobel_x[1][0] * (int)img.at<uchar>(j,i+1)) + (sobel_x[1][1] * (int)img.at<uchar>(j+1,i+1)) + (sobel_x[1][2] * (int)img.at<uchar>(j+2,i+1)) +
         (sobel_x[2][0] * (int)img.at<uchar>(j,i+2)) + (sobel_x[2][1] * (int)img.at<uchar>(j+1,i+2)) + (sobel_x[2][2] * (int)img.at<uchar>(j+2,i+2));
        
         //cout<<"Display i: "<< i <<endl;
         //cout<<"Display j: "<< j <<endl;
         //newimg.at<uchar>(j,i) = pixval;
         //newimg.at<uchar>(j,i) = pixval_x;
         
         int pixval_y =
         (sobel_y[0][0] * (int)newimg.at<uchar>(j,i)) + (sobel_y[0][1] * (int)newimg.at<uchar>(j+1,i)) + (sobel_y[0][2] * (int)newimg.at<uchar>(j+2,i)) +
         (sobel_y[1][0] * (int)newimg.at<uchar>(j,i+1)) + (sobel_y[1][1] * (int)newimg.at<uchar>(j+1,i+1)) + (sobel_y[1][2] * (int)newimg.at<uchar>(j+2,i+1)) +
         (sobel_y[2][0] * (int)newimg.at<uchar>(j,i+2)) + (sobel_y[2][1] * (int)newimg.at<uchar>(j+1,i+2)) + (sobel_y[2][2] * (int)newimg.at<uchar>(j+2,i+2));
         
         int sum = abs(pixval_x) + abs(pixval_y);
         if (sum > 255)
         {
             sum = 255; //for best performance
         }
         cout << sum << endl;
         newimg.at<uchar>(j,i) = sum;
     }
     }
    
    // display the images
    namedWindow("OriginalImage", WINDOW_AUTOSIZE);
    namedWindow("AfterProcess", WINDOW_AUTOSIZE);
    imshow("OriginalImage", img);
    imshow("AfterProcess", newimg);
    waitKey(0);
    return 0;
}
