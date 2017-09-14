# Sobel-Filter
#### Using OpenCV to achieve Sobel Filter without using the built-in function 

## Getting Started
Edge dectection is one of the most fundamental algorithm used in computer vision. It can easily detect the edges in the horizontal and vectical direction by convolving the masks.

## Method
#### Creating two matrics 
**x-direction mask**
```
    sobel_x[0][0] = -1; sobel_x[0][1] = 0; sobel_x[0][2] =1;
    sobel_x[1][0] = -2; sobel_x[1][1] = 0; sobel_x[1][2] =2;
    sobel_x[2][0] = -1; sobel_x[2][1] = 0; sobel_x[2][2] =1;
```
**y-direction mask**
```
    sobel_y[0][0] = -1; sobel_y[0][1] = -2; sobel_y[0][2] = -1;
    sobel_y[1][0] = 0; sobel_y[1][1] = 0; sobel_y[1][2] = 0;
    sobel_y[2][0] = 1; sobel_y[2][1] = 2; sobel_y[2][2] = 1;
```

**Convolving every pixel in the image in x and y direction**
```
for (int j = 0; j<img.rows-2; j++)
    {
        for (int i = 0; i<img.cols-2; i++)
        {
            int pixval_x =
            (sobel_x[0][0] * (int)img.at<uchar>(j,i)) + (sobel_x[0][1] * (int)img.at<uchar>(j+1,i)) + (sobel_x[0][2] * (int)img.at<uchar>(j+2,i)) +
            (sobel_x[1][0] * (int)img.at<uchar>(j,i+1)) + (sobel_x[1][1] * (int)img.at<uchar>(j+1,i+1)) + (sobel_x[1][2] * (int)img.at<uchar>(j+2,i+1)) +
            (sobel_x[2][0] * (int)img.at<uchar>(j,i+2)) + (sobel_x[2][1] * (int)img.at<uchar>(j+1,i+2)) + (sobel_x[2][2] * (int)img.at<uchar>(j+2,i+2));
            
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
```

## Result
