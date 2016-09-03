/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

/* 
 * Base code for CS 251 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * 
 */


#include "cs251_base.hpp"
#include "render.hpp"
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"
#include "magnetic.hpp"
#include <iostream>

namespace cs251
{
  /**  The is the constructor 
   * This is the documentation block for the constructor.
   */ 
  
  
  vector<pair<b2Vec2,bool> > static_bodies;
  vector<b2Body*> metals;
  b2Body* slider;
  dominos_t::dominos_t()
  {
    //Ground
    /*! \var b1 
     * \brief pointer to the body ground 
     */ 
    b2Body* b1;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
      b2BodyDef bd; 
      b2FixtureDef fd;
      fd.restitution = 0.0f;
      fd.friction = 0.0f;
      fd.shape = &shape;
      b1 = m_world->CreateBody(&bd);
      b1->CreateFixture(&fd);
    }

    b2Body* b2;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-40.0f, 40.0f), b2Vec2(40.0f, 40.0f));
      b2BodyDef bd; 
      b2FixtureDef fd;
      fd.restitution = 1.0f;
      fd.friction = 0.0f;
      fd.shape = &shape;
      b2 = m_world->CreateBody(&bd); 
      b2->CreateFixture(&fd);
    }

    b2Body* b3;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(-40.0f, 40.0f));
      b2BodyDef bd; 
      b2FixtureDef fd;
      fd.restitution = 1.0f;
      fd.friction = 0.0f;
      fd.shape = &shape;
      b3 = m_world->CreateBody(&bd); 
      b3->CreateFixture(&fd);
    }

    b2Body* b4;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(40.0f, 0.0f), b2Vec2(40.0f, 40.0f));
      b2BodyDef bd;
      b2FixtureDef fd;
      fd.restitution = 1.0f;
      fd.friction = 0.0f;
      fd.shape = &shape; 
      b4 = m_world->CreateBody(&bd); 
      b4->CreateFixture(&fd);
    }

    b2Body* b5;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(18.0f, 15.0f), b2Vec2(28.0f, 15.0f));
      b2BodyDef bd;
      b2FixtureDef fd;
      fd.restitution = 1.0f;
      fd.friction = 0.0f;
      fd.shape = &shape;
      b5 = m_world->CreateBody(&bd); 
      b5->CreateFixture(&shape, 1.0f);
      shape.Set(b2Vec2(-18.0f, 15.0f), b2Vec2(-28.0f, 15.0f));
      fd.shape = &shape;
      b5->CreateFixture(&fd);
      shape.Set(b2Vec2(-3.0f, 15.0f), b2Vec2(3.0f, 15.0f));
      fd.shape = &shape;
      b5->CreateFixture(&fd);
    }

    {
      metal m1(10.0f,39.0f,m_world);
      // m2.body->ApplyLinearImpulse(b2Vec2(-50.0f,1000.0f),m2.body->GetWorldCenter(),true);
      magnetic_body b1(-20.0f,30.0f,m_world);
      magnetic_body b2(-10.0f,22.0f,m_world);
      magnetic_body b3(10.0f,22.0f,m_world);
      magnetic_body b4(20.0f,30.0f,m_world);

   } 
   

   //The Bucket
    {
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody; 
      bd->position.Set(25.0f, 0.2f);
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 4.0;
      fd1->friction = 0.1;
      // fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(0.6,1.6, b2Vec2(-5.0f,1.0f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 4.0;
      fd2->friction = 0.1;
      // fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(5.0,0.4);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 4.0;
      fd3->friction = 0.1;
      // fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.6,1.6, b2Vec2(5.0f,1.0f), 0);
      fd3->shape = &bs3;

      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);
      slider = box1;

   }
 }
  sim_t *sim = new  sim_t("", dominos_t::create);
}
