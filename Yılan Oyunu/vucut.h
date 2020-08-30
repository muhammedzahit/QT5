#ifndef VUCUT_H
#define VUCUT_H

// bu sınıf yılanın bir vucut uzvunu temsil eder.
class Vucut
{
public:
    Vucut(int _x , int _y);
    Vucut* sonrakiUzuv;
    int x,y;
};

#endif // VUCUT_H
