//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H

#include <array>

namespace ATA {

    /**
     * Vector 2 Templated Class
     * @tparam T
     */
    template<typename T>
    struct Vector2 {
        T x, y;

        Vector2() : x(0), y(0) { }
        Vector2(T posX, T posY) : x(posX), y(posY) { }
        explicit Vector2(T posXY) : x(posXY), y(posXY) { }

        template<class U>
        explicit Vector2(Vector2<U> vector) : x(vector.x), y(vector.y) { }

        /**
         * Methods
         */
        void set(const T nx, const T ny) {
            this->x = nx;
            this->y = ny;
        }

        [[nodiscard]] float magnitude() const {
            return sqrt((x * x) + (y * y));
        }

        [[nodiscard]] Vector2<float> normalised() const {
            return {this->x / magnitude(), this->y / magnitude()};
        }

        /**
         * operators
         */
        Vector2 operator-(const Vector2 &other) {
            return {this->x - other.x, this->y - other.y};
        }

        Vector2 operator+(const Vector2 &other) const {
            return {this->x + other.x, this->y + other.y};
        }

        template<class V>
        auto operator+(const Vector2<V> &other) const {
            return Vector2<T>(this->x + other.x, this->y + other.y);
        }

        template<class V>
        auto operator-(const Vector2<V> &other) const {
            return Vector2<T>(this->x - other.x, this->y - other.y);
        }

        Vector2 &operator+=(const Vector2 &other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        Vector2 operator*(const float value) const {
            return {this->x * value, this->y * value};
        }

        Vector2 operator/(const float value) const {
            return Vector2<T>(this->x / value, this->y / value);
        }

        const Vector2 &operator-=(const Vector2 &other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        bool operator==(const Vector2 &other) const {
            return this->x == other.x && this->y == other.y;
        }

        bool operator!=(const Vector2 &other) const {
            return this->x != other.x || this->y != other.y;
        }

        bool operator>(const Vector2 &other) const {
            return this->magnitude() > other.magnitude();
        }

        bool operator<(const Vector2 &other) const {
            return this->magnitude() < other.magnitude();
        }
    };

    /**
     * Vector 3 Templated class
     * @tparam T
     */
    template<typename T>
    struct Vector3 {
        T x, y, z;

        Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
        Vector3(T posX, T posY, T posZ) : x(posX), y(posY), z(posZ) { }

        std::array<T, 3> asArray() {
            return {x, y, z};
        }
    };

    /**
     * Vector 4 templated class
     * @tparam T
     */
    template<typename T>
    struct Vector4 {
        T x, y, z, w;

        Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
        Vector4(T posX, T posY, T posZ, T posW) : x(posX), y(posY), z(posZ), w(posW) { }

        std::array<T, 4> asArray() {
            return {x, y, z, w};
        }
    };

}// namespace ATA

#endif//HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H
