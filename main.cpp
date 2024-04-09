#include <iostream>
#include <graphics.h>

using namespace std;
int a[10][10];
int width, stanga, height, latura, sus,win=0,nr=1,linie=8,k=1,tip,ok1,culoare_unu,culoare_doi;

void seteaza_culoare()
{
    cout << "NEGRU = 0" << endl;
    cout << "ALBASTRU = 1" << endl;
    cout << "VERDE = 2" << endl;
    cout << "CYAN = 3" << endl;
    cout << "ROSU = 4" << endl;
    cout << "MAGENTA = 5" << endl;
    cout << "MARO = 6" << endl;
    cout << "GRI DESCHIS = 7" << endl;
    cout << "GRI INCHIS = 8" << endl;
    cout << "ALBASTRU DESCHIS = 9" << endl;
    cout << "VERDE DESCHIS = 10" << endl;
    cout << "CYAN DESCHIS = 11" << endl;
    cout << "ROSU DESCHIS = 12" << endl;
    cout << "MAGENTA DESCHIS = 13" << endl;
    cout << "GALBEN = 14" << endl;
    cout << "ALB = 15" << endl;

    cout << "Introduce numarul culoarii pe care o vrei pentru jucatorul 1 (cainii): ";
    cin >> culoare_unu;

    cout << "Introduce numarul culoarii pe care o vrei pentru jucatorul 2 (vulpea): ";
    cin >> culoare_doi;
}


void dog_right(int a[10][10])
{
    if(k<0)
        k=1;
    int ok=0;
    while(ok==0 && k<=5)
    {
        if(a[linie-1][2*k]==0)
        {
            a[linie-1][2*k]=k;
            a[linie][2*k-1]=0;
            ok=1;
        }
        k++;
    }
    if(k>=5) linie--;

}


void dog_left(int a[10][10])
{
    if(k>=5) k=4;
    int ok=0;
    while(ok==0 && k>0)
    {
        if(a[linie-1][2*k-1]==0)
        {
            a[linie-1][2*k-1]=k;
            a[linie][2*k]=0;
            ok=1;
        }
        k--;
    }
    if(k<=0) linie--;

}

void deseneaza_meniu()
{
    setbkcolor(LIGHTBLUE);  ///culoarea fundalului
    cleardevice();      ///goleste ecranul
    setcolor(LIGHTGREEN); ///culoarea textului
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    ///calculeaza centrul ecranului
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    int textWidth = textwidth("Vulpea si Cainii");
    int textHeight = textheight("Vulpea si Cainii");

    int centerX = (screenWidth - textWidth) / 2;
    int centerY = (screenHeight - textHeight) / 2;

    outtextxy(centerX -50, centerY, "1. Jucator VS Jucator");
    outtextxy(centerX -50, centerY + 50, "2. Jucator VS Calculator");
    outtextxy(centerX -50, centerY + 100, "3. Joc secret");
    outtextxy(centerX -50, centerY + 150, "4. Exit");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(centerX - 60, centerY - 100, "Vulpea si Cainii");
}

void verificare_win(int linie,int coloana,int &win)
{
    ///daca au castigat cainii -> vulpea incoltita
    if(a[linie-1][coloana-1]!=0 && a[linie-1][coloana+1]!=0 && a[linie+1][coloana-1]!=0 && a[linie+1][coloana+1]!=0)
        win=1;
}

void verificare_win2(int linie,int coloana,int &win)
{
///daca vulpea a ajuns pe linia 8 ->  a castigat vulpea
    int i,ok=0;
    for(i=1; i<=8; i++)
        if(a[8][i]==2)
            ok=1;
    if(ok==1)
        win=2;
}

void verificare_win3(int linie,int coloana,int &win)
{
///daca vulpea a ajuns pe linia 8 ->  a castigat vulpea  (pentru matricea cu 1,2,3,4,5)
    int i,ok=0;
    for(i=1; i<=8; i++)
        if(a[8][i]==5)
            ok=1;
    if(ok==1)
        win=2;
}

void verificare_win4(int linie,int coloana,int &win)
{
///daca a ajuns cainele pe linia 1 -> mod special
    int i,ok=0;
    for(i=1; i<=8; i++)
        if(a[1][i]==1)
            ok=1;
    if(ok==1)
        win=1;
}

void stergePiesa(int linia, int coloana)
{
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    fillellipse(xmijloc,ymijloc,18,18);
}


void deseneazaPiesa(int linia, int coloana, int jucator)
{
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    if(tip==1 || tip==3)
    {
        if(jucator==1)
        {
            setcolor(culoare_unu);
            setfillstyle(SOLID_FILL,culoare_unu);
            fillellipse(xmijloc,ymijloc,18,18);
        }
        else
        {
            setcolor(culoare_doi);
            setfillstyle(SOLID_FILL,culoare_doi);
            fillellipse(xmijloc,ymijloc,18,18);
        }
    }
    if(tip==2)
    {
        if(jucator<5)
        {
            setcolor(culoare_unu);
            setfillstyle(SOLID_FILL,culoare_unu);
            fillellipse(xmijloc,ymijloc,18,18);
        }
        else
        {
            setcolor(culoare_doi);
            setfillstyle(SOLID_FILL,culoare_doi);
            fillellipse(xmijloc,ymijloc,18,18);
        }
    }
}


void mutare(int jucator)
{
    int repeta=0;
    int linie;
    int coloana;
    setcolor(LIGHTGREEN);
    do
    {
        if(tip==3)
        {
            setcolor(culoare_unu);
            if(jucator==1)
                outtextxy(299, 100, "RANDUL CAINELUI");
            else
            {
                setcolor(culoare_doi);
                outtextxy(300, 100, "RANDUL VULPILOR");
            }
        }
        else
        {
            setcolor(culoare_unu);
            if(jucator==1)
                outtextxy(299, 100, "RANDUL CAINILOR");
            else
            {
                setcolor(culoare_doi);
                outtextxy(300, 100, "RANDUL VULPII");
            }
        }
        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele piesei");
        outtextxy(100, 630, "pe care doriti sa o mutati.");
        delay(2000);
        cout << "Introduceti linia: ";
        cin >> linie;
        char linieText[50];
        sprintf(linieText, "Linia: %d", linie); ///afisarea liniei
        outtextxy(100, 650, linieText);
        cout << "Introduceti coloana: ";
        cin >> coloana;
        char coloanaText[50];
        sprintf(coloanaText, "Coloana: %d", coloana); ///afisarea coloanei
        outtextxy(100, 675, coloanaText);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie>8 || linie<1)||(coloana>8 || coloana<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        else if(a[linie][coloana]!=jucator)
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Nu este randul piesei alese!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti coordonatele piesei corecte.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 700, 610);
            repeta=1;
        }

        else repeta=0;
    }
    while(repeta!=0);

    repeta=0;

    do
    {
        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele unde");
        outtextxy(100, 630, "doriti sa mutati piesa.");
        delay(2000);
        int linie2;
        cout << "Introduceti linia: ";
        cin >> linie2;
        char linieText2[50];
        sprintf(linieText2, "Linia: %d", linie2);
        outtextxy(100, 650, linieText2);
        int coloana2;
        cout << "Introduceti coloana: ";
        cin >> coloana2;
        char coloanaText2[50];
        sprintf(coloanaText2, "Coloana: %d", coloana2);
        outtextxy(100, 675, coloanaText2);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie2>8 || linie2<1)||(coloana2>8 || coloana2<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        if(jucator==1)
        {
            if(linie==linie2+1 && (coloana==coloana2+1 || coloana==coloana2-1))
            {
                if(a[linie2][coloana2]==0)
                {
                    a[linie2][coloana2]=1;
                    a[linie][coloana]=0;
                    stergePiesa(linie,coloana);
                    deseneazaPiesa(linie2,coloana2,jucator);
                    repeta=0;
                }
                else
                {
                    setcolor(LIGHTRED);
                    sprintf(eroare, "Mutarea nu este corecta!", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    repeta=1;
                }
            }
            else
            {
                setcolor(LIGHTRED);
                sprintf(eroare, "Mutarea nu este corecta!", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                repeta=1;

            }

        }
        if(jucator==2)
        {
            verificare_win(linie,coloana,win);
            if(((linie==linie2+1 && (coloana==coloana2+1 || coloana==coloana2-1))) || ((linie==linie2-1 && (coloana==coloana2+1 || coloana==coloana2-1))))
            {
                if(a[linie2][coloana2]==0)
                {
                    a[linie2][coloana2]=2;
                    a[linie][coloana]=0;
                    stergePiesa(linie,coloana);
                    deseneazaPiesa(linie2,coloana2,jucator);
                    repeta=0;

                }
                else
                {
                    setcolor(LIGHTRED);
                    sprintf(eroare, "Mutarea nu este corecta!", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    repeta=1;
                }
            }
            else
            {
                setcolor(LIGHTRED);
                sprintf(eroare, "Mutarea nu este corecta!", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                repeta=1;
            }
            verificare_win2(linie2,coloana2,win);
        }
    }
    while(repeta!=0);
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);  ///acopera textul pentru rand
    fillellipse(400, 10, 150, 150);
}

void deseneaza_tabla()
{
    int i, j;
    width = 400;
    height = 400;
    latura = width / 8;
    sus = (getmaxy() - width) / 2;
    stanga = (getmaxx() - height) / 2;
    setbkcolor(LIGHTBLUE);
    clearviewport();
    setcolor(BLACK);
    rectangle(stanga, sus, stanga + width, sus + height); ///outline-ul tablei

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    for (i = 1; i <= 8; i++)
    {
        char number[2];
        sprintf(number, "%d", i);
        outtextxy(stanga - 30, sus + latura * (i - 1) + latura / 2, number); ///numerotarea pe stanga
    }

    for (j = 1; j <= 8; j++)
    {
        char number[2];
        sprintf(number, "%d", j);
        outtextxy(stanga + latura * (j - 1) + latura / 2, sus - 30, number);  ///numerotarea pe dreapta
    }

    for (i = 1; i <= 8; i++)
    {
        for (j = 1; j <= 8; j++)
        {
            if ((i + j) % 2 == 0)
                setfillstyle(SOLID_FILL, WHITE);  ///patratele
            else
                setfillstyle(SOLID_FILL, DARKGRAY);

            bar(stanga + latura * (i - 1), sus + latura * (j - 1), stanga + latura * i, sus + latura * j);
            rectangle(stanga + latura * (i - 1), sus + latura * (j - 1), stanga + latura * i, sus + latura * j);
        }
    }
}

void doar_vulpe()
{
    int repeta=0;
    int linie;
    int coloana;
    do
    {
        setcolor(culoare_doi);
        outtextxy(300, 100, "RANDUL VULPII");
        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele piesei");
        outtextxy(100, 630, "pe care doriti sa o mutati.");
        delay(2000);
        cout << "Introduceti linia: ";
        cin >> linie;
        char linieText[50];
        sprintf(linieText, "Linia: %d", linie);
        outtextxy(100, 650, linieText);

        cout << "Introduceti coloana: ";
        cin >> coloana;

        char coloanaText[50];
        sprintf(coloanaText, "Coloana: %d", coloana);
        outtextxy(100, 675, coloanaText);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie>8 || linie<1)||(coloana>8 || coloana<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        else if(a[linie][coloana]!=5)
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Nu este randul piesei alese!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti coordonatele piesei corecte.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 700, 610);
            repeta=1;
        }

        else repeta=0;
    }
    while(repeta!=0);

    repeta=0;

    do
    {
        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele unde");
        outtextxy(100, 630, "doriti sa mutati piesa.");
        delay(2000);
        int linie2;
        cout << "Introduceti linia: ";
        cin >> linie2;
        char linieText2[50];
        sprintf(linieText2, "Linia: %d", linie2);
        outtextxy(100, 650, linieText2);
        int coloana2;
        cout << "Introduceti coloana: ";
        cin >> coloana2;
        char coloanaText2[50];
        sprintf(coloanaText2, "Coloana: %d", coloana2);
        outtextxy(100, 675, coloanaText2);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie2>8 || linie2<1)||(coloana2>8 || coloana2<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        verificare_win(linie,coloana,win);
        if(((linie==linie2+1 && (coloana==coloana2+1 || coloana==coloana2-1))) || ((linie==linie2-1 && (coloana==coloana2+1 || coloana==coloana2-1))))
        {
            if(a[linie2][coloana2]==0)
            {
                a[linie2][coloana2]=5;
                a[linie][coloana]=0;
                stergePiesa(linie,coloana);
                deseneazaPiesa(linie2,coloana2,5);
                repeta=0;

            }
            else
            {
                setcolor(LIGHTRED);
                sprintf(eroare, "Mutarea nu este corecta!", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                repeta=1;
            }
        }
        else
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Mutarea nu este corecta!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;
        }
        verificare_win3(linie2,coloana2,win);
    }
    while(repeta!=0);
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    fillellipse(400, 10, 150, 150);
}

void special(int jucator)
{
    int repeta=0;
    int linie;
    int coloana;
    setcolor(LIGHTGREEN);
    do
    {
        setcolor(culoare_unu);
        if(jucator==1)
            outtextxy(299, 100, "RANDUL CAINELUI");
        else
        {
            setcolor(culoare_doi);
            outtextxy(300, 100, "RANDUL VULPILOR");
        }


        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele piesei");
        outtextxy(100, 630, "pe care doriti sa o mutati.");
        delay(2000);
        cout << "Introduceti linia: ";
        cin >> linie;
        char linieText[50];
        sprintf(linieText, "Linia: %d", linie); ///afisarea liniei
        outtextxy(100, 650, linieText);
        cout << "Introduceti coloana: ";
        cin >> coloana;
        char coloanaText[50];
        sprintf(coloanaText, "Coloana: %d", coloana); ///afisarea coloanei
        outtextxy(100, 675, coloanaText);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie>8 || linie<1)||(coloana>8 || coloana<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        else if(a[linie][coloana]!=jucator)
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Nu este randul piesei alese!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti coordonatele piesei corecte.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 700, 610);
            repeta=1;
        }

        else repeta=0;
    }
    while(repeta!=0);

    repeta=0;

    do
    {
        setcolor(LIGHTGREEN);
        outtextxy(100, 610, "Introduceti coordonatele unde");
        outtextxy(100, 630, "doriti sa mutati piesa.");
        delay(2000);
        int linie2;
        cout << "Introduceti linia: ";
        cin >> linie2;
        char linieText2[50];
        sprintf(linieText2, "Linia: %d", linie2);
        outtextxy(100, 650, linieText2);
        int coloana2;
        cout << "Introduceti coloana: ";
        cin >> coloana2;
        char coloanaText2[50];
        sprintf(coloanaText2, "Coloana: %d", coloana2);
        outtextxy(100, 675, coloanaText2);

        delay(2000);

        setfillstyle(SOLID_FILL, getbkcolor());

        bar(-50, 800, 600, 610);

        char eroare[50];
        if((linie2>8 || linie2<1)||(coloana2>8 || coloana2<1))
        {
            setcolor(LIGHTRED);
            sprintf(eroare, "Coordonatele nu sunt corecte!", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            sprintf(eroare, "Introduceti iar coordonatele.", eroare);
            outtextxy(100, 670, eroare);
            delay(2000);
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(-50, 800, 500, 610);
            repeta=1;

        }
        if(jucator==1)
        {
            if(linie==linie2+1 && (coloana==coloana2+1 || coloana==coloana2-1))
            {
                if(a[linie2][coloana2]==0)
                {
                    a[linie2][coloana2]=1;
                    a[linie][coloana]=0;
                    stergePiesa(linie,coloana);
                    deseneazaPiesa(linie2,coloana2,jucator);
                    repeta=0;
                    verificare_win4(linie2,coloana2,win);
                }
                else
                {
                    setcolor(LIGHTRED);
                    sprintf(eroare, "Mutarea nu este corecta!", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    repeta=1;
                }
            }
            else
            {
                setcolor(LIGHTRED);
                sprintf(eroare, "Mutarea nu este corecta!", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                repeta=1;

            }

        }
        if(jucator==2)
        {
            if(((linie==linie2+1 && (coloana==coloana2+1 || coloana==coloana2-1))) || ((linie==linie2-1 && (coloana==coloana2+1 || coloana==coloana2-1))))
            {
                if(a[linie2][coloana2]==0)
                {
                    a[linie2][coloana2]=2;
                    a[linie][coloana]=0;
                    stergePiesa(linie,coloana);
                    deseneazaPiesa(linie2,coloana2,jucator);
                    repeta=0;

                }
                else
                {
                    setcolor(LIGHTRED);
                    sprintf(eroare, "Mutarea nu este corecta!", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                    outtextxy(100, 670, eroare);
                    delay(2000);
                    setfillstyle(SOLID_FILL, getbkcolor());
                    bar(-50, 800, 500, 610);
                    repeta=1;
                }
            }
            else
            {
                setcolor(LIGHTRED);
                sprintf(eroare, "Mutarea nu este corecta!", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                sprintf(eroare, "Introduceti iar coordonatele.", eroare);
                outtextxy(100, 670, eroare);
                delay(2000);
                setfillstyle(SOLID_FILL, getbkcolor());
                bar(-50, 800, 500, 610);
                repeta=1;
            }

        }
    }
    while(repeta!=0);
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);  ///acopera textul pentru rand
    fillellipse(400, 10, 150, 150);
}

int main()
{
    int i,j;
    int gd = DETECT, gm;

    seteaza_culoare();

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    deseneaza_meniu();

    char choice;

    do
    {
        choice = getch();

        switch (choice)
        {
        case '1':
            cleardevice();
            tip=1;
            break;
        case '2':
            tip=2;
            ///cod vs ai
            break;
        case '3':
            tip=3;
            ///vulpile vs caine
            break;
        case '4':
            closegraph();
            exit(0);
        default:
            break;
        }

        deseneaza_meniu();

    }
    while (tip==0);

    closegraph();

    if(tip==1)     ///jocul de baza
    {
        ///initializare matrice
        for(j=0; j<=9; j++)
        {
            a[0][j]=-1;
            a[j][0]=-1;
            a[j][9]=-1;
            a[9][j]=-1;
        }
        for(j=1; j<=8; j++)
            if(j%2==1)
                a[8][j]=1;

        a[1][4]=2;

        initwindow(800,800,"Cainii si vulpea");
        deseneaza_tabla();
        for(i=1; i<=8; i++)
            for(j=1; j<=8; j++)
                if(a[i][j]==1)
                    deseneazaPiesa(i,j,1);
                else if(a[i][j]==2)
                    deseneazaPiesa(i,j,2);
        while(win==0)
        {
            mutare(1);
            mutare(2);
        }
        if(win==1)
        {
            setcolor(culoare_unu);
            outtextxy(270, 650, "AU CASTIGAT CAINII!");
        }
        else
        {
            setcolor(culoare_doi);
            outtextxy(270, 650, "A CASTIGAT VULPEA!");
        }
        getch();
        closegraph();
    }
    else if(tip==2)
    {

        int rand=1;
        for(j=0; j<=9; j++)
        {
            a[0][j]=-1;
            a[j][0]=-1;
            a[j][9]=-1;
            a[9][j]=-1;
        }
        for(j=1; j<=8; j++)
            if(j%2==1)
            {
                a[8][j]=nr; ///initializare caini cu 1,2,3,4
                nr++;
            }

        a[1][4]=5;

        initwindow(800,800,"Cainii si vulpea");
        deseneaza_tabla();
        for(i=1; i<=8; i++)
            for(j=1; j<=8; j++)
                if(a[i][j]>0 && a[i][j]<5)
                    deseneazaPiesa(i,j,a[i][j]);
                else if(a[i][j]==5)
                    deseneazaPiesa(i,j,5);

        delay(2000);

        while(win==0)
        {
            if(rand==1)
            {
                if(linie%2==0)
                {
                    delay(1000);
                    dog_right(a);
                    clearviewport();
                    deseneaza_tabla();
                    for(i=1; i<=8; i++)
                        for(j=1; j<=8; j++)
                            if(a[i][j]>0 && a[i][j]<5)
                                deseneazaPiesa(i,j,a[i][j]);
                            else if(a[i][j]==5)
                                deseneazaPiesa(i,j,5);



                }
                else
                {
                    delay(1000);
                    dog_left(a);
                    clearviewport();
                    deseneaza_tabla();
                    for(i=1; i<=8; i++)
                        for(j=1; j<=8; j++)
                            if(a[i][j]>0 && a[i][j]<5)
                                deseneazaPiesa(i,j,a[i][j]);
                            else if(a[i][j]==5)
                                deseneazaPiesa(i,j,5);


                }
                rand=2;
            }
            else
            {
                doar_vulpe();
                rand=1;
            }
        }
        if(win==1)
        {
            setcolor(culoare_unu);
            outtextxy(270, 650, "AU CASTIGAT CAINII!");
        }
        else
        {
            setcolor(culoare_doi);
            outtextxy(270, 650, "A CASTIGAT VULPEA!");
        }
        getch();
        closegraph();
    }
    else if(tip==3)
    {
        for(j=0; j<=9; j++)
        {
            a[0][j]=-1;
            a[j][0]=-1;
            a[j][9]=-1;
            a[9][j]=-1;
        }
        for(j=1; j<=8; j++)
            if(j%2==0)
                a[1][j]=2;

        a[8][5]=1;

        initwindow(800,800,"Vulpile si cainele");
        deseneaza_tabla();
        for(i=1; i<=8; i++)
            for(j=1; j<=8; j++)
                if(a[i][j]==1)
                    deseneazaPiesa(i,j,1);
                else if(a[i][j]==2)
                    deseneazaPiesa(i,j,2);
        while(win==0)
        {
            special(1);
            special(2);
        }
        if(win==1)
        {
            setcolor(culoare_unu);
            outtextxy(270, 650, "A CASTIGAT CAINELE!");
        }
        getch();
        closegraph();

    }

    return 0;
}

