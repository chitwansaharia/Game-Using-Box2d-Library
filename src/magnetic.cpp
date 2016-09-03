#include "magnetic.hpp"
#include "cs251_base.hpp"
#include <cstdio>
using namespace std;
namespace cs251{
	/*
		Constructing magnetic body given position
	*/
		magnetic_body::magnetic_body(float x,float y,b2World* m_world)
    	{ 
      
	      b2CircleShape circle;
	      circle.m_radius = 2.0;
	  
	      b2FixtureDef ballfd;
	      ballfd.shape = &circle;
	      ballfd.density = 50.0f;
	      ballfd.friction = 0.0f;
	      ballfd.restitution = 0.0f;
	      b2BodyDef ballbd;
	      ballbd.type = b2_staticBody;
	      ballbd.position.Set(x,y);
	      body = m_world->CreateBody(&ballbd);
	      body->CreateFixture(&ballfd);
	      static_bodies.push_back(make_pair(body->GetWorldCenter(),1));

	  	}

	  	metal::metal(float x,float y,b2World* m_world)
    	{ 
      
	      b2CircleShape circle;
	      circle.m_radius = 0.7;
	  
	      b2FixtureDef ballfd;
	      ballfd.shape = &circle;
	      ballfd.density = 50.0f;
	      ballfd.friction = 0.0f;
	      ballfd.restitution = 0.0f;
	      b2BodyDef ballbd;
	      ballbd.type = b2_dynamicBody;
	      ballbd.position.Set(x,y);
	      body = m_world->CreateBody(&ballbd);
	      body->CreateFixture(&ballfd);
	      metals.push_back(body);
	  	}
}
