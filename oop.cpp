#include <bits/stdc++.h>
using namespace std;

class Thong_tin
{
private:
    // mkh: ma khach hang
    // nls: ngay lap so
    string name, mkh, cmnd, nls;

public:
    Thong_tin(string ten, string ma_kh, string cm_nd, string ngay_ls)
    {
        name = ten;
        mkh = ma_kh;
        cmnd = cm_nd;
        nls = ngay_ls;
    }
    void output(ofstream &outfile)
    {
        outfile << "| " << setw(13) << name;
        outfile << " | " << setw(5) << mkh;
        outfile << " |  " << cmnd;
        outfile << " |  " << setw(11) << nls;
    }
    void out_put()
    {
        cout << "| " << setw(13) << name;
        cout << " | " << setw(5) << mkh;
        cout << " |  " << cmnd;
        cout << " |  " << setw(11) << nls;
    }
    string tenn()
    {
        return name;
    }
    string Cmnd()
    {
        return cmnd;
    }
};

// KKH: khong ki han
class KKH : public Thong_tin
{
private:
    long Tien_lai;
    float tong_laisuat;
    long Tien_gui;
    float Lai_suat;
    long tongtienlai;
    float tonglaisuat = 0;

public:
    KKH(string ten, string ma_kh, string cm_nd, string ngay_ls, long tg, float ls, int kh) : Thong_tin(ten, ma_kh, cm_nd, ngay_ls)
    {
        Tien_gui = tg;
        Lai_suat = ls;
        tongtienlai = 0;
    }
    long tinh_tienlai(int thang)
    {
        Tien_lai = Tien_gui * Lai_suat * thang;
        tongtienlai += Tien_lai;
        return Tien_lai;
    }
    float tinh_laisuat(int thang)
    {
        tong_laisuat = Lai_suat * thang;
        return tong_laisuat;
    }
    long tong_tl()
    {
        return tongtienlai;
    }
    long Sodu()
    {
        return Tien_gui;
    }
    void output(ofstream &outfile)
    {
        Thong_tin ::output(outfile);
        outfile << " | " << setw(6) << " ";
    }
    void out_put()
    {
        Thong_tin ::out_put();
        cout << " | " << setw(6) << " ";
    }
    long Tienguithem(long tiengui)
    {
        Tien_gui += tiengui;
        return Tien_gui;
    }
    long Tien_rut(long tienrut)
    {
        Tien_gui -= tienrut;
        return Tien_gui;
    }
    string tenn()
    {
        return Thong_tin ::tenn();
    }
    string Cmnd()
    {
        return Thong_tin ::Cmnd();
    }
};

// CKH: co ki han
class CKH : Thong_tin
{
private:
    float tong_laisuat;
    long Tien_lai;
    long Tien_gui;
    float Lai_suat;
    int Ki_han;
    long tongtienlai;
    float tonglaisuat = 0;

public:
    CKH(string ten, string ma_kh, string cm_nd, string ngay_ls, long tg, float ls, int kh) : Thong_tin(ten, ma_kh, cm_nd, ngay_ls)
    {
        Tien_gui = tg;
        Lai_suat = ls;
        Ki_han = kh;
        tongtienlai = 0;
    }
    long tinh_tienlai(int thang)
    {
        if (thang >= Ki_han)
        {
            Tien_lai = Tien_gui * Lai_suat * thang;
            tongtienlai += Tien_lai;
            return Tien_lai;
        }
        else
            return Tien_lai = 0;
    }
    float tinh_laisuat(int thang)
    {
        if (thang >= Ki_han)
        {
            tong_laisuat = Lai_suat * thang;
            return tong_laisuat;
        }
        else
            return tong_laisuat = 0;
    }
    long tong_tl()
    {
        return tongtienlai;
    }
    long Sodu()
    {
        return Tien_gui;
    }
    void output(ofstream &outfile)
    {
        Thong_tin ::output(outfile);
        outfile << " | " << setw(6) << Ki_han;
    }
    void out_put()
    {
        Thong_tin ::out_put();
        cout << " | " << setw(6) << Ki_han;
    }
    long Tienguithem(long tiengui)
    {
        Tien_gui += tiengui;
        return Tien_gui;
    }
    long Tien_rut(long tienrut)
    {
        Tien_gui -= tienrut;
        return Tien_gui;
    }
};

class Ngan_hang : public KKH, public CKH
{
private:
    // mst: ma so thue
    // sdt: so dien thoai
    // nh: ngan hang
    // dc: dia chi
    // em: email
    // t: thang
    string Ten_nh, Dia_chi, email, sdt;
    long mst;
    int thang, b, a;
    long tongtienlai;
    float tonglaisuat;

public:
    Ngan_hang(string name, string mkh, string cmnd, string nls, string nh, string dc, string em, long ma_thue, string so_dt, int t, long tg, float ls, int kh, int b1, int a1) : KKH(name, mkh, cmnd, nls, tg, ls, kh), CKH(name, mkh, cmnd, nls, tg, ls, kh)
    {
        Ten_nh = nh;
        Dia_chi = dc;
        email = em;
        mst = ma_thue;
        sdt = so_dt;
        thang = t;
        b = b1;
        a = a1;
        tongtienlai = 0;
        tonglaisuat = 0;
    }
    void tienlai(ofstream &outfile)
    {
        if (b == 1)
            outfile << setw(12) << CKH ::tinh_tienlai(thang) << " |";
        if (b == 0)
            outfile << setw(12) << KKH ::tinh_tienlai(thang) << " |";
    }
    void laisuat(ofstream &outfile)
    {
        if (b == 1)
            outfile << setw(10) << CKH ::tinh_laisuat(thang) << " |";
        if (b == 0)
            outfile << setw(10) << KKH ::tinh_laisuat(thang) << " |";
    }
    void Sodu(ofstream &outfile)
    {
        if (b == 1)
            outfile << setw(11) << CKH ::Sodu() << " |";
        if (b == 0)
            outfile << setw(11) << KKH ::Sodu() << " |";
    }
    void out(ofstream &outfile)
    {
        outfile << "_________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
        outfile << "| " << setw(11) << " Ho ten " << setw(6) << " |  " << setw(5) << " MKH  | " << setw(11) << " CMND  " << setw(20) << " | Ngay lap so  | Ki han | " << setw(5) << " Ten ngan hang  | " << setw(15) << " Dia chi " << setw(5) << " | " << setw(15) << " Email " << setw(9) << " | " << setw(10) << " Ma so thue  | " << setw(10) << " SDT " << setw(10) << " | " << setw(5) << " Lai suat "
                << " | " << setw(7) << " So du " << setw(6) << " | " << setw(7) << " Tien lai " << setw(4) << " | " << endl;
        outfile << "_________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    }
    void output(ofstream &outfile)
    {
        if (b == 1)
        {
            CKH ::output(outfile);
            outfile << " | " << setw(15) << Ten_nh;
            outfile << " | " << setw(17) << Dia_chi;
            outfile << " | " << setw(21) << email;
            outfile << " | " << setw(12) << mst;
            outfile << " | " << setw(17) << sdt << " | " << setw(5);
            laisuat(outfile);
            Sodu(outfile);
            tienlai(outfile);
            outfile << endl;
            outfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        if (b == 0)
        {
            KKH ::output(outfile);
            outfile << " | " << setw(15) << Ten_nh;
            outfile << " | " << setw(17) << Dia_chi;
            outfile << " | " << setw(21) << email;
            outfile << " | " << setw(12) << mst;
            outfile << " | " << setw(17) << sdt << " | " << setw(5);
            laisuat(outfile);
            Sodu(outfile);
            tienlai(outfile);
            outfile << endl;
            outfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    void tien_lai()
    {
        if (b == 1)
            cout << setw(12) << CKH ::tinh_tienlai(thang) << " |";
        if (b == 0)
            cout << setw(12) << KKH ::tinh_tienlai(thang) << " |";
    }
    void lai_suat()
    {
        if (b == 1)
            cout << setw(10) << CKH ::tinh_laisuat(thang) << " |";
        if (b == 0)
            cout << setw(10) << KKH ::tinh_laisuat(thang) << " |";
    }
    void So_du()
    {
        if (b == 1)
            cout << setw(11) << CKH ::Sodu() << " |";
        if (b == 0)
            cout << setw(11) << KKH ::Sodu() << " |";
    }
    void outt()
    {
        cout << "_________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
        cout << "| " << setw(11) << " Ho ten " << setw(6) << " |  " << setw(5) << " MKH  | " << setw(11) << " CMND  " << setw(20) << " | Ngay lap so  | Ki han | " << setw(5) << " Ten ngan hang  | " << setw(15) << " Dia chi " << setw(5) << " | " << setw(15) << " Email " << setw(9) << " | " << setw(10) << " Ma so thue  | " << setw(10) << " SDT " << setw(10) << " | " << setw(5) << " Lai suat "
             << " | " << setw(7) << " So du " << setw(6) << " | " << setw(7) << " Tien lai " << setw(4) << " | " << endl;
        cout << "_________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    }
    void out_put()
    {
        if (b == 1)
        {
            CKH ::out_put();
            cout << " | " << setw(15) << Ten_nh;
            cout << " | " << setw(17) << Dia_chi;
            cout << " | " << setw(21) << email;
            cout << " | " << setw(12) << mst;
            cout << " | " << setw(17) << sdt << " | " << setw(5);
            lai_suat();
            So_du();
            tien_lai();
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        if (b == 0)
        {
            KKH ::out_put();
            cout << " | " << setw(15) << Ten_nh;
            cout << " | " << setw(17) << Dia_chi;
            cout << " | " << setw(21) << email;
            cout << " | " << setw(12) << mst;
            cout << " | " << setw(17) << sdt << " | " << setw(5);
            lai_suat();
            So_du();
            tien_lai();
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    void Chuc_nang()
    {
        int x;
        cout << "Nhap so can thuc thi:\n1) Rut tien!\n2) Gui tien!\n3) Xem so du!" << endl;
        cout << "Moi nhap: ", cin >> x;
        if (x == 1)
        {
            long Tien_rut;
        nhaplaitienrut:
            cout << "Nhap so tien muon rut: ", cin >> Tien_rut;
            if (b == 1)
            {
                if (Tien_rut <= CKH ::tinh_tienlai(thang))
                {
                    CKH ::Tien_rut(Tien_rut);
                    cout << "Rut tien thanh cong!" << endl;
                }
                else
                {
                    int y;
                    cout << "So tien khong du de thuc hien giao dich!" << endl;
                    cout << "Ban co muon nhap lai(0/1): ", cin >> y;
                    if (y == 1)
                        goto nhaplaitienrut;
                }
            }
            if (b == 0)
            {
                if (Tien_rut <= KKH ::tinh_tienlai(thang))
                {
                    KKH ::Tien_rut(Tien_rut);
                    cout << "Rut tien thanh cong!" << endl;
                }
                else
                {
                    int y;
                    cout << "So tien khong du de thuc hien giao dich!" << endl;
                    cout << "Ban co muon nhap lai(0/1): ", cin >> y;
                    if (y == 1)
                        goto nhaplaitienrut;
                }
            }
        }
        if (x == 2)
        {
            long tien_gui;
            cout << "Nhap so tien muon gui: ", cin >> tien_gui;
            if (b == 1)
            {
                CKH ::Tienguithem(tien_gui);
                cout << "Gui tien thanh cong!" << endl;
            }
            if (b == 0)
            {
                KKH ::Tienguithem(tien_gui);
                cout << "Gui tien thanh cong!" << endl;
            }
        }
        if (x == 3)
        {
            outt();
            out_put();
        }
    }
    void tim_kiem(string sdt_cantim, string name_cantim, string cmnd_cantim, int &z, int &Sdt, int &Nm, int &Cm)
    {
        if (z == 1)
        {
            for (int i = 0; i < 1; i++)
            {
                if (sdt == sdt_cantim)
                {
                    Chuc_nang();
                    Sdt = 1;
                }
                else
                    Sdt++;
            }
        }
        if (z == 2)
        {
            for (int i = 0; i < 1; i++)
            {
                if (KKH ::tenn() == name_cantim)
                {
                    Chuc_nang();
                    Nm = 1;
                }
                else
                    Nm++;
            }
        }
        if (z == 3)
        {
            for (int i = 0; i < 1; i++)
            {
                if (KKH ::Cmnd() == cmnd_cantim)
                {
                    Chuc_nang();
                    Cm = 1;
                }
                else
                    Cm++;
            }
        }
    }
    long tong_tl()
    {
        if (b == 1)
            tongtienlai = CKH ::tong_tl();
        if (b == 0)
            tongtienlai = KKH ::tong_tl();
        return tongtienlai;
    }
};

int main()
{
    // a: tong so
    // b: xac dinh loại so tiet kiem
    // mst: ma so thue
    // mkh: ma khach hang
    // nls: ngay lap so
    int a, b;
    string Ten_nh, Dia_chi, email, sdt;
    string name, mkh, cmnd, nls;
    long Tien_lai, Tien_gui, mst;
    float Lai_suat;
    int Ki_han, thang, n = 0;
    Ngan_hang *s[20];
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("out.txt");
    infile >> a;
    for (int i = 0; i < a; i++)
    {
        infile >> b;
        if (b == 1)
        {
            infile.ignore();
            getline(infile, name, ',');
            getline(infile, mkh, ',');
            getline(infile, cmnd, ',');
            getline(infile, nls, ',');
            getline(infile, Ten_nh, ',');
            getline(infile, Dia_chi, ',');
            infile >> mst;
            infile.ignore();
            getline(infile, sdt, ',');
            getline(infile, email, ',');
            infile >> Ki_han;
            infile.ignore();
            infile >> thang;
            infile.ignore();
            infile >> Lai_suat;
            infile.ignore();
            infile >> Tien_gui;
        }
        if (b == 0)
        {
            infile.ignore();
            getline(infile, name, ',');
            getline(infile, mkh, ',');
            getline(infile, cmnd, ',');
            getline(infile, nls, ',');
            getline(infile, Ten_nh, ',');
            getline(infile, Dia_chi, ',');
            infile >> mst;
            infile.ignore();
            getline(infile, sdt, ',');
            getline(infile, email, ',');
            infile >> thang;
            infile.ignore();
            infile >> Lai_suat;
            infile.ignore();
            infile >> Tien_gui;
        }
        s[n++] = new Ngan_hang(name, mkh, cmnd, nls, Ten_nh, Dia_chi, email, mst, sdt, thang, Tien_gui, Lai_suat, Ki_han, b, a);
    }
    s[0]->out(outfile);
    for (int i = 0; i < a; i++)
    {
        s[i]->output(outfile);
    }
    // tongtl: tong tien lai
    long tongtl = 0;
    for (int i = 0; i < a; i++)
        tongtl += s[i]->tong_tl();
    outfile << "| " << setw(13) << " Tong"
            << " | " << setw(9) << " | " << setw(14) << " | " << setw(15) << " | " << setw(9) << "| " << setw(18) << " | " << setw(20) << " | " << setw(24) << " | " << setw(15) << " | " << setw(20) << " | " << setw(13) << " | " << setw(13) << " | " << setw(11) << tongtl << " | " << endl;
    outfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    int z = 1, Sdt = 1, Nm = 1, Cm = 1;
    long tong_tl = 0;
    string sdt_cantim, name_cantim, cmnd_cantim;
nhaplailenh:
    cerr << "Nhap so can thuc thi:\n1) Tim kiem bang sdt!\n2) Tim kiem bang ten khach hang!\n3) Tim kiem bang CMND!\n4) Xem thong tin toan bo so! " << endl;
    cout << "Moi nhap: ", std ::cin >> z;
    switch (z)
    {
    case 1:
    nhapsdt:
        cout << "Moi nhap sdt can tim: ";
        cin >> sdt_cantim;
        break;
    case 2:
    nhaptenkh:
        cout << "Moi nhap ten khach hang can tim: ";
        cin >> name_cantim;
        break;
    case 3:
    nhapemailkh:
        cout << "Moi nhap CMND khach hang can tim: ";
        cin >> cmnd_cantim;
        break;
    case 4:
        s[0]->outt();
            for (int i = 0; i < a; i++)
            {
                s[i]->out_put();
            }
            for (int i = 0; i < a; i++)
                tong_tl += s[i]->tong_tl();
            cout << "| " << setw(13) << " Tong"
                 << " | " << setw(9) << " | " << setw(14) << " | " << setw(15) << " | " << setw(9) << "| " << setw(18) << " | " << setw(20) << " | " << setw(24) << " | " << setw(15) << " | " << setw(20) << " | " << setw(13) << " | " << setw(13) << " | " << setw(11) << tong_tl - tongtl << " | " << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    // if (z == 1)
    // {
    // nhapsdt:
    //     cout << "Moi nhap sdt can tim: ";
    //     cin >> sdt_cantim;
    // }
    // if (z == 2)
    // {
    // nhaptenkh:
    //     cout << "Moi nhap ten khach hang can tim: ";
    //     cin >> name_cantim;
    // }
    // if (z == 3)
    // {
    // nhapemailkh:
    //     cout << "Moi nhap CMND khach hang can tim: ";
    //     cin >> cmnd_cantim;
    // }
    // if (z == 4)
    // {
    //     s[0]->outt();
    //     for (int i = 0; i < a; i++)
    //     {
    //         s[i]->out_put();
    //     }
    //     for (int i = 0; i < a; i++)
    //         tong_tl += s[i]->tong_tl();
    //     cout << "| " << setw(13) << " Tong"
    //          << " | " << setw(9) << " | " << setw(14) << " | " << setw(15) << " | " << setw(9) << "| " << setw(18) << " | " << setw(20) << " | " << setw(24) << " | " << setw(15) << " | " << setw(20) << " | " << setw(13) << " | " << setw(13) << " | " << setw(11) << tong_tl - tongtl << " | " << endl;
    //     cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    // }
    for (int i = 0; i < a; i++)
    {
        s[i]->tim_kiem(sdt_cantim, name_cantim, cmnd_cantim, z, Sdt, Nm, Cm);
    }
    if (Sdt > a)
    {
        int so_dt;
        Sdt = 1;
        cout << "Khong tim thay so dien thoai can tim!\nBan co muon nhap lai(0/1): ", cin >> so_dt;
        if (so_dt == 1)
            goto nhapsdt;
    }
    if (Nm > a)
    {
        int name_kh;
        Nm = 1;
        cout << "Khong tim thay ten khach hang can tim!\nBan co muon nhap lai(0/1): ", cin >> name_kh;
        if (name_kh == 1)
            goto nhaptenkh;
    }
    if (Cm > a)
    {
        int Cmnd_kh;
        Cm = 1;
        cout << "Khong tim thay email khach hang can tim!\nBan co muon nhap lai(0/1): ", cin >> Cmnd_kh;
        if (Cmnd_kh == 1)
            goto nhapemailkh;
    }
    int o;
    cout << "Ban co muon thuc hien lai(0/1): ";
    cin >> o;
    if (o == 1)
        goto nhaplailenh;
    outfile << "================================================================== Sau khi thuc hien cac thao tac!======================================================================" << endl;
    s[0]->out(outfile);
    for (int i = 0; i < a; i++)
    {
        s[i]->output(outfile);
    }
    outfile << "| " << setw(13) << " Tong"
            << " | " << setw(9) << " | " << setw(14) << " | " << setw(15) << " | " << setw(9) << "| " << setw(18) << " | " << setw(20) << " | " << setw(24) << " | " << setw(15) << " | " << setw(20) << " | " << setw(13) << " | " << setw(13) << " | " << setw(11) << tong_tl - tongtl << " | " << endl;
    outfile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}