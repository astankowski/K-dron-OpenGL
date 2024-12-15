#include <GL/glew.h>
#include <iostream>

#include "kdron.h"
#include "vertices.h"

Kdron::Kdron(float init_velocity, float init_angle){
    velocity_ = init_velocity;
    angle_ = init_angle;
    animated_ = true;
}

void Kdron::Left(){
    model_matrix_.RotateAboutY(1);
}

void Kdron::Right(){
    model_matrix_.RotateAboutY(-1);
}

void Kdron::Up(){
    model_matrix_.RotateAboutX(1);
}

void Kdron::Down(){
    model_matrix_.RotateAboutX(-1);
}


void Kdron::Move(float delta_t){
    if (!animated_) return;
    angle_ += delta_t * velocity_;
    if(angle_>360) angle_ -= 360;
    if(angle_<-360) angle_ += 360;
    model_matrix_.SetUnitMatrix();
    model_matrix_.RotateAboutX(angle_);
    model_matrix_.RotateAboutY(angle_);
}

void Kdron::SpeedUp(){
    velocity_ *= 1.09544511501;
}

void Kdron::SlowDown(){
    velocity_ /= 1.09544511501;
}

void Kdron::ToggleAnimated(){
    animated_ = ! animated_;
}

void Kdron::Initialize(){
    const ColorVertex kVertices[12] =
    {   // x y z
        { { -1.0f, -1.0f,  1.0f, 1.0f }, { 0, 0, 1, 1 } }, //0
        { { -1.0f, 0.0f,  1.0f, 1.0f }, { 1, 1, 0.5, 1 } }, //1
        { { 0.0f, -1.0f,  1.0f, 1.0f }, { 1, 0.7, 1, 1 } }, //2
        { { 1.0f, -1.0f, 1.0f, 1.0f }, { 0, 0, 0.7, 1 } }, //3
        { { 1.0f, -1.0f, -1.0f, 1.0f }, { 1, 0.7, 1, 1 } }, //4
        { { 1.0f, -.0f, -1.0f, 1.0f }, { 0, 1, 0, 1 } }, //5
        { { 1.0f, 0.0f, 0.0f, 1.0f }, { 0.5, 0.7, 1, 1 } }, //6
        { { 0.0f, 1.0f, -1.0f, 1.0f }, { 1, 0.7, 1, 1 } }, //7
        { { -1.0f, 0.0f, -1.0f, 1.0f }, { 0, 1, 0.7, 1 } }, //8
        { { -1.0f, 0.0f, 0.0f, 1.0f }, { 1, 0.7, 1, 1 } }, //9
        { { -1.0f, -1.0f, -1.0f, 1.0f }, { 0, 0, 1, 1 } }, //10
        { { 1.0f, 0.0f, 1.0f, 1.0f }, { 1, 0, 0.7, 1 } } //11
    };

    const GLuint kIndices[57] =
    {
        3,11,6, 3,6,4, 4,6,5,
        7,9,2, 7,6,2,
        2,1,9, 2,6,11,
        2,3,11,
        0,1,2,
        0,3,10, 10,3,4,
        7,5,6,
        9,7,8,
        0,1,9, 0,10,9, 8,10,9,
        8,10,4, 5,4,8, 7,8,3
    };

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertices), kVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(kVertices[0]), (GLvoid*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(kVertices[0]),
                          (GLvoid*) sizeof(kVertices[0].position));
    glEnableVertexAttribArray(1);


    glGenBuffers(1, &index_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(kIndices), kIndices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Kdron::Draw(const ModelProgram &program) const{

    glUseProgram(program);
    glBindVertexArray(vao_);

    program.SetModelMatrix(model_matrix_);

    glDrawElements(GL_TRIANGLES, 51, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);


}
