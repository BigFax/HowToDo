#ifndef CLASS_ETAT
#define CLASS_ETAT

class Etat
{
    private :
        bool occupe;
        int direction;
    public :
        Etat();
        Etat(bool o, int d);
        bool get_o();
        int get_d();
        void set_o(bool o);
        void set_d(int d);
        void modif_d();
};

#endif
