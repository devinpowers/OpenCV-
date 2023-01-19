# OpenCV-
OpenCV Projects
Install OpenCV dependencies: OpenCV has several dependencies that need to be installed. You can install these dependencies using Homebrew by running the following command:

```
brew install pkg-config cmake jpeg libpng libtiff openexr eigen tbb
```


Download OpenCV: You can download the latest version of OpenCV from the OpenCV website. Or you can use the following command:


```
wget https://github.com/opencv/opencv/archive/4.5.2.zip
```

Unzip the archive: Unzip the archive that you just downloaded.
```
unzip 4.5.2.zip
```

Build and install OpenCV: Now you can build and install OpenCV by running the following commands:

```
cd opencv-4.5.2
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j4
sudo make install
```

Configure Environment Variable: After installing OpenCV, you need to configure the environment variable to point to the location of the OpenCV library. You can add the following lines to your .bash_profile or .bashrc file

```
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

Test the Installation: To test the installation, you can create a new file named test.cpp and paste the following code in it


```
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    std::cout << CV_VERSION << std::endl;
    return 0;
}
```

then run the command:

```
g++ test.cpp -o test `pkg-config opencv4 --cflags --libs`

```

and finally run the binary



```
./test
```
