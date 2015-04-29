#ifndef CLASS_FOURMI
#define CLASS_FOURMI

class Fourmi
{
    private :
        int i, j;
        int d;
    public :
        Fourmi(Plateau& plat);
        int get_d();
        friend bool operator<(const Fourmi& a, const Fourmi& b);
};

#endif
