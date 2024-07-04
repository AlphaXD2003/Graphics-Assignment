#include <iostream>

struct Point {
    float x, y;
};

const int MAX_POINTS = 20;

bool inside(const Point& p, const Point& a, const Point& b) {
    return (b.x - a.x) * (p.y - a.y) > (b.y - a.y) * (p.x - a.x);
}

Point intersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
    float A1 = a2.y - a1.y;
    float B1 = a1.x - a2.x;
    float C1 = A1 * a1.x + B1 * a1.y;

    float A2 = b2.y - b1.y;
    float B2 = b1.x - b2.x;
    float C2 = A2 * b1.x + B2 * b1.y;

    float det = A1 * B2 - A2 * B1;

    Point intersect;
    intersect.x = (B2 * C1 - B1 * C2) / det;
    intersect.y = (A1 * C2 - A2 * C1) / det;
    return intersect;
}

void sutherlandHodgman(Point subjectPolygon[], int& subjectSize, Point clipPolygon[], int clipSize) {
    Point input[MAX_POINTS];
    for (int i = 0; i < subjectSize; ++i) {
        input[i] = subjectPolygon[i];
    }
    int inputSize = subjectSize;

    for (int j = 0; j < clipSize; ++j) {
        Point clipEdgeStart = clipPolygon[j];
        Point clipEdgeEnd = clipPolygon[(j + 1) % clipSize];

        Point output[MAX_POINTS];
        int outputSize = 0;

        for (int i = 0; i < inputSize; ++i) {
            Point current = input[i];
            Point previous = input[(i + inputSize - 1) % inputSize];

            if (inside(current, clipEdgeStart, clipEdgeEnd)) {
                if (!inside(previous, clipEdgeStart, clipEdgeEnd)) {
                    output[outputSize++] = intersection(previous, current, clipEdgeStart, clipEdgeEnd);
                }
                output[outputSize++] = current;
            } else if (inside(previous, clipEdgeStart, clipEdgeEnd)) {
                output[outputSize++] = intersection(previous, current, clipEdgeStart, clipEdgeEnd);
            }
        }

        inputSize = outputSize;
        for (int i = 0; i < outputSize; ++i) {
            input[i] = output[i];
        }
    }

    subjectSize = inputSize;
    for (int i = 0; i < inputSize; ++i) {
        subjectPolygon[i] = input[i];
    }
}

int main() {
    Point subjectPolygon[MAX_POINTS] = {{50, 150}, {200, 50}, {350, 150}, {350, 300}, {250, 300}, {200, 250}, {150, 350}, {100, 250}, {50, 200}};
    int subjectSize = 9;

    Point clipPolygon[MAX_POINTS] = {{100, 100}, {300, 100}, {300, 300}, {100, 300}};
    int clipSize = 4;

    sutherlandHodgman(subjectPolygon, subjectSize, clipPolygon, clipSize);

    std::cout << "Clipped Polygon:\n";
    for (int i = 0; i < subjectSize; ++i) {
        std::cout << "(" << subjectPolygon[i].x << ", " << subjectPolygon[i].y << ")\n";
    }

    return 0;
}
