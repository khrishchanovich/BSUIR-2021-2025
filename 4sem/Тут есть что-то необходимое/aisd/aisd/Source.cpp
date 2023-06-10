
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() = default;
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double bruteForce(Point P[], int n, Point& p1, Point& p2) {
    double minDist = 1e9; // Инициализируем минимальное расстояние большим числом
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = distance(P[i], P[j]);
            if (dist < minDist) {
                minDist = dist;
                p1 = P[i];
                p2 = P[j];
            }
        }
    }
    return minDist;
}

double stripClosest(Point strip[], int size, double d, Point& p1, Point& p2) {
    double minDist = d;
    sort(strip, strip + size, compareY);
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                p1 = strip[i];
                p2 = strip[j];
            }
        }
    }
    return minDist;
}

double closestUtil(Point Px[], Point Py[], const int n, Point& p1, Point& p2) {
    if (n <= 3) {
        return bruteForce(Px, n, p1, p2);
    }
    const int mid = n / 2;
    Point midPoint = Px[mid];
    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; ++i) {
        if (Py[i].x <= midPoint.x) {
            Pyl[li++] = Py[i];
        }
        else {
            Pyr[ri++] = Py[i];
        }
    }
    double dl = closestUtil(Px, Pyl, mid, p1, p2);
    double dr = closestUtil(Px + mid, Pyr, n - mid, p1, p2);
    double d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(Py[i].x - midPoint.x) < d) {
            strip[j++] = Py[i];
        }
    }
    return min(d, stripClosest(strip, j, d, p1, p2));
}

double closest(Point P[], int n, Point& p1, Point& p2) {
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; ++i) {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    sort(Px, Px + n, compareX);
    sort(Py, Py + n, compareY);
    return closestUtil(Px, Py, n, p1, p2);
}

int main() {

    const int n = 10000;

    Point P[n];

    //  srand(time(NULL));

    for (int i = 0; i < n; i++) {

        unsigned x = (unsigned)rand() % 1000000;

        unsigned y = (unsigned)rand() % 1000000;

        new(P + i) Point(x, y);

        cout << "{" << P[i].x << ", " << P[i].y << "},\n";
    }

    Point p1, p2;

    double minDist = closest(P, n, p1, p2);

    cout << "Минимальное расстояние между парами точек: " << minDist << endl;

    cout << "Ближайшие точки: (" << p1.x << ", " << p1.y << ") и (" << p2.x << ", " << p2.y << ")" << endl;
    return 0;
}