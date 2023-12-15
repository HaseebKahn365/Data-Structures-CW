

class Prefference{
    public:
    bool wifi;
    bool bluetooth;
    int heaterTemp;
    int lightSetIntensity;
    bool tv;
    bool usesLaptop;
    bool usesPhone;
    bool usesTablet;
    bool usesPC;
    Prefference(){
        wifi = false;
        bluetooth = false;
        heaterTemp = 0;
        lightSetIntensity = 0;
        tv = false;
        usesLaptop = false;
        usesPhone = false;
        usesTablet = false;
        usesPC = false;
    }
    //setter for all the services
    void setWifi(bool w){
        wifi = w;
    }

    void setBluetooth(bool b){
        bluetooth = b;
    }

    void setHeaterTemp(int t){
        heaterTemp = t;
    } 

    void setLightSetIntensity(int i){
        lightSetIntensity = i;
    }

    void setTv(bool t){
        tv = t;
    }

    void setUsesLaptop(bool l){
        usesLaptop = l;
    }

    void setUsesPhone(bool p){
        usesPhone = p;
    }

    void setUsesTablet(bool t){
        usesTablet = t;
    }

    void setUsesPC(bool p){
        usesPC = p;
    }


};

