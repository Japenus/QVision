// #ifndef BEIZERCURVE_H
// #define BEIZERCURVE_H

// #include <QWidget>

// class BeizerCurve:public QObject
// {
//     Q_OBJECT
// public:
//     explicit BeizerCurve(const QVector<Point> &points);

//     ///< 生成贝塞尔曲线点
//     void Calculate(int outPointNum=11);
//     ///< 获取曲线点集
//     QVector<Point> GetOutputPoints();
//     struct Point
//     {
//         Point(): x(0), y(0), z(0) {}
//         Point(double x, double y, double z): x(x), y(y), z(z) {}

//         Point operator *(double num) {
//             return Point(x*num, y*num, z*num);
//         }
//         Point operator +(const Point& p) {
//             return Point(x+p.x, y+p.y, z+p.z);
//         }
//         void operator +=(const Point& p) {
//             this->x += p.x;
//             this->y += p.y;
//             this->z += p.z;
//         }

//         double x;
//         double y;
//         double z;
//     };

// protected:
//     ///< 求组合数
//     uint64_t combination(int n, int i);
//     ///< 计算单项值
//     double bernstein(int n, int i, double t);


// private:
//     QVector<Point> m_pointsInput;
//     QVector<Point> m_pointsOutput;
//     QMap<uint32_t, uint64_t> m_combVal;
// };

// #endif // BEIZERCURVE_H
