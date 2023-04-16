#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

void draw_line(float x1, float y1, float x2, float y2);

int main()
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x21;
    float y21;
    float x22;
    float y22;
    
    cout << "Enter coordinats X and Y" << endl;
    cout << "X1: ";
    cin >> x1;
    cout << "Y1: ";
    cin >> y1;
    cout << "X2: ";
    cin >> x2;
    cout << "Y2: ";
    cin >> y2;
    cout << "X21: ";
    cin >> x21;
    cout << "Y21: ";
    cin >> y21;
    cout << "X22: ";
    cin >> x22;
    cout << "Y22: ";
    cin >> y22;
    
    system("cls");

    draw_line(x1, y1, x2, y2);
    

    _getch();

    while (true)
    {
        system("cls");

        int choice;

        cout << "If you want to shift of X or Y - enter 1" << endl;
        cout << "If you want to turn - enter 2" << endl;
        cout << "If you want to scale - enter 3" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            float shift_x;
            float shift_y;

            system("cls");
            cout << "Enter how much you want to shift X (if you want shift to left enter minus): ";
            cin >> shift_x;
            cout << "Enter how much you want to shift Y (if you want shift to up enter minus): ";
            cin >> shift_y;
            system("cls");

            x1 += shift_x;
            y1 += shift_y;
            x2 += shift_x;
            y2 += shift_y;

            draw_line(x1, y1, x2, y2);
            _getch();
        }

        else if (choice == 2)
        {
            system("cls");

            float f;
            cout << "Enter degree: ";
            cin >> f;
            
            float x0 = x2;
            float y0 = y2;

            x2 = int(x1 + (x0 - x1) * cos(f * (3.14 / 180)) - (y0 - y1) * sin(f * (3.14 / 180)));
            y2 = int(y1 + (x0 - x1) * sin(f * (3.14 / 180)) + (y0 - y1) * cos(f * (3.14 / 180)));

            draw_line(x1, y1, x2, y2);
            _getch();
        }
        
        else if (choice == 3)
        {
            system("cls");
            cout << "If you want to decrease, enter < 1" << endl;
            cout << "If you want to increase, enter > 1" << endl;
            cout << "Enter how much to reduce: ";

            float reduce;
            cin >> reduce;

            float x0 = x1;
            float y0 = y1;

            x1 = int(x1 * (1 - reduce) + x1 * reduce);
            y1 = int(y1 * (1 - reduce) + y1 * reduce);
            x2 = int(x0 * (1 - reduce) + x2 * reduce);
            y2 = int(y0 * (1 - reduce) + y2 * reduce);

            system("cls");
            draw_line(x1, y1, x2, y2);
            _getch();
            
        }

        else
        {
            exit(1);
        }
    }
    
 
    return 0;
}

void draw_line(float x1, float y1, float x2, float y2)
{
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2 = err;

    for (;;)
    {

        SetPixel(hdc, x1, y1, RGB(255, 0, 255));
        if (x1 == x2 && y1 == y2) break;
        e2 = err;
        if (e2 > (-dx))
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }
}
