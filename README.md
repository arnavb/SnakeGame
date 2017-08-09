# SnakeGame

[![language(C++)](https://img.shields.io/badge/language-c%2B%2B-brightgreen.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Powered by SFML](https://img.shields.io/badge/powered%20by-SFML-68f442.svg)](https://www.sfml-dev.org/)
[![Packagist](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://github.com/arnavb/SnakeGame/blob/master/LICENSE.txt)

A simple clone of the game Snake made using SFML and Visual C++. This project, and all associated code, is licensed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License) as outlined under [LICENSE.txt](https://github.com/arnavb/SnakeGame/blob/master/LICENSE.txt).

<b>Download Links for Windows</b>
<ul>
<li><b>x86: </b><a href="https://drive.google.com/file/d/0B5LejbIN6T8gVmNBNXFJSHl1ckU/view?usp=sharing">https://drive.google.com/file/d/0B5LejbIN6T8gVmNBNXFJSHl1ckU/view?usp=sharing</a> (Works for x86 and x64)</li>
<li><b>x64: </b><a href="https://drive.google.com/file/d/0B5LejbIN6T8gUGJXNFotZ0dJZTA/view?usp=sharing">https://drive.google.com/file/d/0B5LejbIN6T8gUGJXNFotZ0dJZTA/view?usp=sharing</a> (Recommended for x64)</li>
</ul>

Instructions:

1. Download the appropriate `.zip` compressed folder.
2. Extract the files to a directory of your choice.
3. Run the application `Snake!` inside the directory.

Dependencies:
- [SFML](http://sfml-dev.org/)

To compile the code on Visual Studio, download the files and place them in a WIN32 application. Then download and link SFML as outlined [here](https://www.sfml-dev.org/tutorials/2.4/start-vc.php).

To compile the code using g++, download the files and place them in a directory of your choice. Change the file `main.cpp` to the following:

```C++

#include "SnakeGameApp.hpp"
#include <stdexcept>

int main()
{
    try
    {
        SnakeGameApp game;
        game.run();
    }
    catch (const std::exeception& error)
    {
        //Error handling code
    }
    catch (...)
    {
        //Error handling code
    }
}

```
Then download and link SFML as outlined [here](https://www.sfml-dev.org/tutorials/2.4/start-linux.php). Make sure the four resource files that end in `.ttf` or `.png` are in the same directory as the executable.

For other platforms, check out the [tutorials](https://www.sfml-dev.org/tutorials/2.4/) for how to set up the game._

_This repository __does NOT__ accept pull requests and all pull requests will effectively be ignored.
