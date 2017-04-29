# Kinect Depth Data Filters
A tiny C++ library of four filters for incoming Kinect depth data: In-painting with FMM, Kalman filter and delay filter. 
Library was tested on Kinect for Xbox 360 and Asus X-tion sensors. 
The results are covered in paper: http://ieeexplore.ieee.org/document/6986855/

## Filters in action
[![Filters in action](https://img.youtube.com/vi/2KhGaCjEuaQ/0.jpg)](https://www.youtube.com/watch?v=2KhGaCjEuaQ)

## Paper details

### Abstract
This paper presents techniques to eliminate flickering pixels and fill irregular shaped 
patches and gaps in depth information obtained from the Microsoft Kinect. 
Due to the limitations of the structured light technology used by the Kinect, 
a significant noise occurs when capturing depth information. 
The paper proposes an approach based on the Kalman filter and image in-painting techniques 
in order to improve the temporal stability of the depth map and fill occlusion areas. 
Depth data from current frame and previous frame are combined. The coefficient of combination 
responds to the rate of depth map changes. The filtrated depth frames are included iteratively in the filtering process. 
Finally, the missing depth areas are obtained applying an image in-painting technique based on the fast marching method. 
The proposed approach can be used as a preprocessing stage before using the depth data for image recognition purposes.

* *Published in:* 2014 International Conference on Mechanical Engineering, Automation and Control Systems (MEACS)
* *Date of Conference:* 16-18 Oct. 2014
* *Date Added to IEEE Xplore:* 18 December 2014
 
 
### ISBN Information:
 
* INSPEC Accession Number: 14823093
* DOI: 10.1109/MEACS.2014.6986855
* Publisher: IEEE
* Conference Location: Tomsk, Russia
