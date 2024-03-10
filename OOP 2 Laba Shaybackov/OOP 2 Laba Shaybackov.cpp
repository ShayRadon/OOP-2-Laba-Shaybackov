#include <iostream>
#include <vector>
#include <string>

class Point {
public:

    Point(int x, int y) {
        this->x = x;
        this->y = y;
        std::cout << "[CONSLOE INFO] Point(int x, int y)" << std::endl;
    }

    Point() {
        x = 0;
        y = 0;
        std::cout << "[CONSLOE INFO] Point()" << std::endl;
    }

    Point(const Point &P) : x(P.x), y(P.y) {
        std::cout << "[CONSLOE INFO] Point(const Point &P)" << std::endl;
    }

    void Set_cord(int x, int y) {
        if ((x <= 1920 or y <= 1920) and (x >= 0 or y >= 0)) {
            this->x = x;
            this->y = y;
            std::cout << "[CONSOLE INFO] "<<"[FUNC::Set_cord]"<< std::endl;
        }
        else {
            std::cout << "[CONSOLE INFO] "<<"[ERROR::Bad_cord]" << std::endl;
        }
    }

    void Get_Pos() {
        std::cout << "X = " << this->x << std::endl;
        std::cout << "Y = " << this->y << std::endl;
        std::cout << "[CONSOLE INFO] " << "[FUNC::Get_Pos]" << std::endl;
    }

    void Current_info() {
        std::cout << "X = " << this->x << std::endl;
        std::cout << "Y = " << this->y << std::endl;
        std::cout << "[CONSOLE INFO] " << "[FUNC::Current_info]" << std::endl;
    }

    void Move(std::string Move) {
        if (Move == "N") {
            if (this->x < 1920)
            {
                this->x = this->x + 1;
                std::cout << "[CONSOLE INFO] " << "[FUNC::Move]" << std::endl;

            }
            else {
                std::cout << "[CONSOLE INFO] "<<"[ERROR::Bad_cord]" << std::endl;
            }
        }
        else if (Move == "S") {
            if (this->x > 0) 
            {
                this->x = this->x - 1;
                std::cout << "[CONSOLE INFO] " << "[FUNC::Move]" << std::endl;
            }
            else {
                std::cout << "[CONSOLE INFO] " << "[ERROR::Bad_cord]" << std::endl;
            }
        }
        else if (Move == "W") {
            if (this->y > 0)
            {
                this->y = this->y - 1;
                std::cout << "[CONSOLE INFO] " << "[FUNC::Move]" << std::endl;
            }
            else {
                std::cout << "[CONSOLE INFO] " << "[ERROR::Bad_cord]" << std::endl;
            }
        }
        else if (Move == "E") {
            if (this->y < 1920)
            {
                this->y = this->y + 1;
                std::cout << "[CONSOLE INFO] " << "[FUNC::Move]" << std::endl;

            }
            else {
                std::cout << "[CONSOLE INFO] " << "[ERROR::Bad_cord]" << std::endl;
            }
        }
        
    }
    ~Point() {
        std::cout<< "[CONSOLE INFO] " << "~Point()" << std::endl;
    }
protected:
    int x;
    int y;

};

class Circle : public Point {
protected:
    int radius;
public:
    Circle() : Point(0,0), radius(0) {
        std::cout << "[CONSLOE INFO] Circle()" << std::endl;
    }
    Circle(int x, int y, int R) : Point(x,y), radius(R){
        std::cout << "[CONSLOE INFO] Circle(int x, int y, int R)" << std::endl;
    }
    Circle(const Circle& C) : Point(C), radius(C.radius) {
        std::cout << "[CONSLOE INFO] Circle(const Circle& C)" << std::endl;
    }
    int Set_Radius(int R) {
        radius = R;
        std::cout << "[CONSOLE INFO] " << "[FUNC::Set_Radius]" << std::endl;
        return radius;
    }
    int Get_Radius() {
        std::cout << "Radius = " << radius << std::endl;
        std::cout << "[CONSOLE INFO] " << "[FUNC::Get_Radius]" << std::endl;
        return radius;
    }
    void Current_info() {
        Get_Pos();
        Get_Radius();
    }
    ~Circle() {
        std::cout << "[CONSOLE INFO] " << "~Circle()" << std::endl;
    }
};


int main()
{
    {
        Point p0;
    }

    Point* P_list[5];
    P_list[0] = new Point;
    P_list[0]->Set_cord(3244, 2344);
    P_list[0]->Set_cord(123,432);

    Point P(0, 4);
    P.Move("W");
    P.Get_Pos();
    P_list[1] = new Point(P);

    P_list[0]->Get_Pos();
    P_list[0]->Move("S");
    P_list[0]->Get_Pos();

    Point P1 = P;
    Point P2 = Point(123, 231);


    Circle C(12, 23, 4);

    P_list[2] = new Circle(C);
    C.Get_Pos();
    C.Current_info();
    delete P_list[0];
    delete P_list[2];
}


