#include <windows.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>


#define BTN_ID_1 101
#define BTN_ID_2 102
#define BTN_ID_3 103
#define BTN_ID_4 104
#define BTN_ID_5 105
#define BTN_ID_6 106
#define BTN_ID_7 107
#define BTN_ID_8 108
#define BTN_ID_9 109
#define BTN_ID_0 110
#define BTN_ID_SOMAR 111
#define BTN_ID_SUBTRAIR 112
#define BTN_ID_DIVIDIR 113
#define BTN_ID_MULTIPLICAR 114
#define BTN_ID_IGUAL 115
#define BTN_ID_VIRGULA 116
#define BTN_ID_APAGAR 117
#define TEXTO_ID 201

    static std::string resultado = "";
    static std::string strn1 = "";
    static bool strn1ok = false;
    static std::string strn2 = "";
    static bool strn2ok = false;
    static std::string operador = "";
    static std::string operacao = strn1+operador+strn2;
    char texto[16];
    HWND hEDIT;
    static HFONT hFonte = NULL;
    static HFONT hFonteBtn = NULL;


    void numero(char alga){
        if (!resultado.empty()){
                    strn1=resultado;
                    resultado="";
                    strn2+=alga;
                } else if (!operador.empty()){
                    strn2+=alga;
                } else{
                    strn1+=alga;
                }

    }

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    static HWND hBtn1, hBtn2, hBtn3,hBtn4, hBtn5, hBtn6, hBtn7,hBtn8,hBtn9,hBtn10, hBtn11, hBtn12, hBtn13,hBtn14, hBtn15, hBtn16, hBtn17, hEDIT;

    switch (msg){
    case WM_CREATE:
        {

        hBtn1 = CreateWindow("BUTTON","1", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,50,200,50,50,hwnd,(HMENU)BTN_ID_1,NULL,NULL);

        hBtn2 = CreateWindow("BUTTON","2", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,100,200,50,50,hwnd,(HMENU)BTN_ID_2,NULL,NULL);

        hBtn3 = CreateWindow("BUTTON","3", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,150,200,50,50,hwnd,(HMENU)BTN_ID_3,NULL,NULL);

        hBtn4 = CreateWindow("BUTTON","4", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,50,150,50,50,hwnd,(HMENU)BTN_ID_4,NULL,NULL);

        hBtn5 = CreateWindow("BUTTON","5", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,100,150,50,50,hwnd,(HMENU)BTN_ID_5,NULL,NULL);

        hBtn6 = CreateWindow("BUTTON","6", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,150,150,50,50,hwnd,(HMENU)BTN_ID_6,NULL,NULL);

        hBtn7 = CreateWindow("BUTTON","7", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,50,100,50,50,hwnd,(HMENU)BTN_ID_7,NULL,NULL);

        hBtn8 = CreateWindow("BUTTON","8", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,100,100,50,50,hwnd,(HMENU)BTN_ID_8,NULL,NULL);

        hBtn9 = CreateWindow("BUTTON","9", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,150,100,50,50,hwnd,(HMENU)BTN_ID_9,NULL,NULL);

        hBtn10 = CreateWindow("BUTTON","0", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,100,250,50,50,hwnd,(HMENU)BTN_ID_0,NULL,NULL);

        hBtn11 = CreateWindow("BUTTON","/", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,200,100,50,50,hwnd,(HMENU)BTN_ID_DIVIDIR,NULL,NULL);

        hBtn12 = CreateWindow("BUTTON","X", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,200,150,50,50,hwnd,(HMENU)BTN_ID_MULTIPLICAR,NULL,NULL);

        hBtn13 = CreateWindow("BUTTON","-", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,200,200,50,50,hwnd,(HMENU)BTN_ID_SUBTRAIR,NULL,NULL);

        hBtn14 = CreateWindow("BUTTON","+", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,200,250,50,50,hwnd,(HMENU)BTN_ID_SOMAR,NULL,NULL);

        hBtn15 = CreateWindow("BUTTON","=", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,50,300,200,50,hwnd,(HMENU)BTN_ID_IGUAL,NULL,NULL);

        hBtn16 = CreateWindow("BUTTON","c", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,50,250,50,50,hwnd,(HMENU)BTN_ID_APAGAR,NULL,NULL);

        hBtn17 = CreateWindow("BUTTON",",", WS_VISIBLE|WS_CHILD| BS_DEFPUSHBUTTON,150,250,50,50,hwnd,(HMENU)BTN_ID_VIRGULA,NULL,NULL);

        hEDIT = CreateWindowEx(WS_EX_CLIENTEDGE, "Edit", "", WS_CHILD|WS_VISIBLE|ES_RIGHT|ES_READONLY,50,20,200,55,hwnd,(HMENU)TEXTO_ID,NULL,NULL);

        hFonte = CreateFont(-35,0,0,0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,"Segoe UI");

        hFonteBtn = CreateFont(-25,0,0,0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,"Segoe UI");

        SendMessage( hBtn1, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn2, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn3, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn4, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn5, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn6, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn7, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn8, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn9, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn10, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn11, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn12, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn13, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn14, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn15, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn16, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

        SendMessage( hBtn17, WM_SETFONT, (WPARAM)hFonteBtn,TRUE);

                        break;
                        }

    case WM_COMMAND:
        switch (LOWORD(wParam)){

            case BTN_ID_1:
                numero('1');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_2:
                numero('2');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;


            case BTN_ID_3:
                numero('3');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_4:
                numero('4');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_5:
                numero('5');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_6:
                numero('6');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_7:
                numero('7');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_8:
                numero('8');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_9:
                numero('9');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;
            case BTN_ID_0:
                numero('0');
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_SOMAR:
                operador = "+";
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_SUBTRAIR:
                operador = "-";
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_DIVIDIR:
                operador = "/";
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_MULTIPLICAR:
                operador = "x";
                operacao=strn1+operador+strn2;
                SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                SetWindowText(hEDIT, operacao.c_str() );
                break;

            case BTN_ID_IGUAL:
                 if (operador == "+"){
                        double n1 = std::stod(strn1);
                        double n2 = std::stod(strn2);
                        double valor=n1+n2;
                        std::ostringstream oss;
                        oss<<std::fixed<<std::setprecision(10)<<valor;
                        std::string str = oss.str();
                        str.erase(str.find_last_not_of('0')+1,std::string::npos);
                        if (str.back()== '.') str.pop_back();
                        operacao=str;
                        std::replace(operacao.begin(), operacao.end(),'.',',');
                        SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                        SetWindowText(hEDIT, operacao.c_str() );
                        resultado = operacao;
                        strn1 = "";
                        strn2 = "";

                } else if (operador == "-"){
                    double n1 = std::stod(strn1);
                    double n2 = std::stod(strn2);
                    double valor=n1-n2;
                     std::ostringstream oss;
                    oss<<std::fixed<<std::setprecision(10)<<valor;
                    std::string str = oss.str();
                    str.erase(str.find_last_not_of('0')+1,std::string::npos);
                    if (str.back()== '.') str.pop_back();
                    operacao=str;
                    std::replace(operacao.begin(), operacao.end(),'.',',');
                    SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                    SetWindowText(hEDIT, operacao.c_str() );
                    resultado = operacao;
                    strn1 = "";
                    strn2 = "";

                } else if (operador == "x"){
                    double n1 = std::stod(strn1);
                    double n2 = std::stod(strn2);
                    double valor=n1*n2;
                     std::ostringstream oss;
                    oss<<std::fixed<<std::setprecision(10)<<valor;
                    std::string str = oss.str();
                    str.erase(str.find_last_not_of('0')+1,std::string::npos);
                    if (str.back()== '.') str.pop_back();
                    operacao=str;
                    std::replace(operacao.begin(), operacao.end(),'.',',');
                    SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                    SetWindowText(hEDIT, operacao.c_str() );
                    resultado = operacao;
                    strn1 = "";
                    strn2 = "";

                } else if (operador == "/"){
                     if (strn2=="0"){
                        operacao="!!!";
                        SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                        SetWindowText(hEDIT, operacao.c_str() );
                        MessageBox(hwnd,"Cuidado ao tentar dividir por zero !!!","Advertencia",MB_OK|MB_ICONINFORMATION);
                    }else{
                        double n1 = std::stod(strn1);
                        double n2 = std::stod(strn2);
                        double valor=n1/n2;
                         std::ostringstream oss;
                        oss<<std::fixed<<std::setprecision(10)<<valor;
                        std::string str = oss.str();
                        str.erase(str.find_last_not_of('0')+1,std::string::npos);
                        if (str.back()== '.') str.pop_back();
                        operacao=str;
                        std::replace(operacao.begin(), operacao.end(),'.',',');
                        SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                        SetWindowText(hEDIT, operacao.c_str() );
                        resultado = operacao;
                        strn1 = "";
                        strn2 = "";
                }}
                break;

            case BTN_ID_VIRGULA:
                numero('.');

                break;

            case BTN_ID_APAGAR:
                  resultado = "";
                  strn1 = "";
                  strn1ok = false;
                  strn2 = "";
                  strn2ok = false;
                  operador = "";
                  operacao = "";
                  SendMessage(hEDIT, WM_SETFONT, (WPARAM)hFonte,TRUE);
                  SetWindowText(hEDIT, operacao.c_str() );
                  break;
        }
        break;

    case WM_DESTROY:PostQuitMessage(0);
        break;
    }
return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdshow){
    const char CLASS_NAME[] = "CALCULADORA";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "CALCULADORA",WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,320,440, NULL, NULL, hInstance, NULL);ShowWindow(hwnd, nCmdshow);
    UpdateWindow(hwnd);
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0,0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            }
            return 0;
}
