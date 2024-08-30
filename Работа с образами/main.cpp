#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Movable {
public:
    virtual void move(double dx, double dy, double dz) = 0;
    virtual ~Movable() = default;
};

class Scalable {
public:
    virtual void scale(double sx, double sy, double sz) = 0;
    virtual ~Scalable() = default;
};

class UniformScaling {
public:
    virtual void scaleUniform(double factor) = 0;
    virtual ~UniformScaling() = default;
};

class Transformation : public Movable, public Scalable {
public:
    void move(double dx, double dy, double dz) override {
        std::cout << "Moving by (" << dx << ", " << dy << ", " << dz << ")\n";
    }

    void scale(double sx, double sy, double sz) override {
        std::cout << "Scaling by (" << sx << ", " << sy << ", " << sz << ")\n";
    }
};

class UniformTransformation : public UniformScaling {
public:
    void scaleUniform(double factor) override {
        std::cout << "Uniform scaling by factor " << factor << "\n";
    }
};

class Line : public Shape, public Transformation, public UniformTransformation {
public:
    void draw() const override {
        std::cout << "Drawing a line\n";
    }
};

class Rectangle : public Shape, public Transformation, public UniformTransformation {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle\n";
    }
};

class Circle : public Shape, public Transformation, public UniformTransformation {
public:
    void draw() const override {
        std::cout << "Drawing a circle\n";
    }
};

class Cylinder : public Shape, public Transformation, public UniformTransformation {
public:
    void draw() const override {
        std::cout << "Drawing a cylinder\n";
    }
};

class Parallelepiped : public Shape, public Transformation, public UniformTransformation {
public:
    void draw() const override {
        std::cout << "Drawing a parallelepiped\n";
    }
};

// Функция для тестирования
void testShapes() {
    std::unique_ptr<Shape> line = std::make_unique<Line>();
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>();
    std::unique_ptr<Shape> circle = std::make_unique<Circle>();
    std::unique_ptr<Shape> cylinder = std::make_unique<Cylinder>();
    std::unique_ptr<Shape> parallelepiped = std::make_unique<Parallelepiped>();

    line->draw();
    rectangle->draw();
    circle->draw();
    cylinder->draw();
    parallelepiped->draw();

    // Применяем преобразования
    if (auto* transform = dynamic_cast<Transformation*>(line.get())) {
        transform->move(1.0, 2.0, 3.0);
    }

    if (auto* transform = dynamic_cast<Transformation*>(rectangle.get())) {
        transform->scale(2.0, 2.0, 1.0);
    }

    if (auto* uniformTransform = dynamic_cast<UniformScaling*>(parallelepiped.get())) {
        uniformTransform->scaleUniform(1.5);
    }
}

int main() {
    testShapes();
    return 0;
}
