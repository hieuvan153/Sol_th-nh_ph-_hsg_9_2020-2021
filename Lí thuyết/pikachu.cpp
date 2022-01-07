#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long x, y;
};

struct Vector
{
    long long x, y;
};

struct Line
{
    long long A, B, C;
};

/// PHƯƠNG PHÁP HÌNH HỌC ///

// Khoảng cách giữa 2 điểm
long double Dist(Point P1, Point P2)
{
    long double x = P1.x - P2.x;
    long double y = P1.y - P2.y;
    return sqrt(x * x + y * y); // Pytago 
}

// Tính vector tạo thành bởi 2 điểm
Vector Vect(Point P1, Point P2)
{
    return {P2.x - P1.x, P2.y - P1.y};
}

// Vị trí tương đối giữa 3 Điểm
long long CCW(Point P1, Point P2, Point P3)
{
    Vector P12 = Vect(P1, P2);
    Vector P23 = Vect(P2, P3);
    long long k = P12.x * P23.y - P12.y * P23.y; // Vẽ hình chia trường hợp để chứng minh

    if (k == 0)
        return 0; // nằm trên
    if (k > 0)
        return 1; // bên phải
    return -1;    // bên trái
}

// Phương trình đường thẳng tổng quát
Line Extract(Point P1, Point P2)
{
    Line P12;
    P12.A = P2.y - P1.y;
    P12.B = P1.x - P2.x;
    P12.C = P2.x * P1.y - P1.x * P2.y;
    return P12;
}

// Hàm tính
long long ff(Point P, Line L)
{
    return L.A * P.x + L.B * P.y - L.C;
}

// Khoảng cách giữa điểm và đường thẳng
long double DistPL(Point P, Line L)
{
    long double ffP = ff(P, L);
    long double sqrA = L.A * L.A;
    long double sqrB = L.B * L.B;
    long double sqrAB = sqrt(sqrA + sqrB);

    //           |A * P.x + B * P.y + C|  
    // DistPL = -------------------------
    //              √(A * A + B * B) 
    
    return ffP / sqrAB;
}

// Vị trí tương đối giữa điểm và đường thẳng
// Tương tự CCW

// Xác định điểm M có thuộc đoạn thẳng P1P2
bool PoInLi(Point M, Point P1, Point P2)
{
    return (CCW(M, P1, P2) && // M, P1, P2 thẳng hàng
            (M.x >= min(P1.x, P2.x)) && (M.x <= max(P1.x, P2.x)) && // M nằm trong khoảng
            (M.y >= min(P1.y, P2.y)) && (M.y <= max(P1.y, P2.y)));  // giữa P1 và P2
}