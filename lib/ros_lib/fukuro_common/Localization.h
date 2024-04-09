#ifndef _ROS_fukuro_common_Localization_h
#define _ROS_fukuro_common_Localization_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace fukuro_common
{

  class Localization : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _estimate_pos_type;
      _estimate_pos_type estimate_pos;
      typedef geometry_msgs::Pose2D _estimate_pos_descrete_type;
      _estimate_pos_descrete_type estimate_pos_descrete;
      uint32_t particles_length;
      typedef geometry_msgs::Pose2D _particles_type;
      _particles_type st_particles;
      _particles_type * particles;
      typedef geometry_msgs::Pose2D _best_estimation_type;
      _best_estimation_type best_estimation;
      uint32_t weights_length;
      typedef float _weights_type;
      _weights_type st_weights;
      _weights_type * weights;
      typedef float _best_estimation_weight_type;
      _best_estimation_weight_type best_estimation_weight;
      typedef int32_t _grid_size_type;
      _grid_size_type grid_size;

    Localization():
      estimate_pos(),
      estimate_pos_descrete(),
      particles_length(0), st_particles(), particles(nullptr),
      best_estimation(),
      weights_length(0), st_weights(), weights(nullptr),
      best_estimation_weight(0),
      grid_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->estimate_pos.serialize(outbuffer + offset);
      offset += this->estimate_pos_descrete.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->particles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->particles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->particles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->particles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->particles_length);
      for( uint32_t i = 0; i < particles_length; i++){
      offset += this->particles[i].serialize(outbuffer + offset);
      }
      offset += this->best_estimation.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->weights_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->weights_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->weights_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->weights_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weights_length);
      for( uint32_t i = 0; i < weights_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->weights[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->best_estimation_weight);
      union {
        int32_t real;
        uint32_t base;
      } u_grid_size;
      u_grid_size.real = this->grid_size;
      *(outbuffer + offset + 0) = (u_grid_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grid_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grid_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grid_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->estimate_pos.deserialize(inbuffer + offset);
      offset += this->estimate_pos_descrete.deserialize(inbuffer + offset);
      uint32_t particles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      particles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      particles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      particles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->particles_length);
      if(particles_lengthT > particles_length)
        this->particles = (geometry_msgs::Pose2D*)realloc(this->particles, particles_lengthT * sizeof(geometry_msgs::Pose2D));
      particles_length = particles_lengthT;
      for( uint32_t i = 0; i < particles_length; i++){
      offset += this->st_particles.deserialize(inbuffer + offset);
        memcpy( &(this->particles[i]), &(this->st_particles), sizeof(geometry_msgs::Pose2D));
      }
      offset += this->best_estimation.deserialize(inbuffer + offset);
      uint32_t weights_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->weights_length);
      if(weights_lengthT > weights_length)
        this->weights = (float*)realloc(this->weights, weights_lengthT * sizeof(float));
      weights_length = weights_lengthT;
      for( uint32_t i = 0; i < weights_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_weights));
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->best_estimation_weight));
      union {
        int32_t real;
        uint32_t base;
      } u_grid_size;
      u_grid_size.base = 0;
      u_grid_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grid_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grid_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grid_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grid_size = u_grid_size.real;
      offset += sizeof(this->grid_size);
     return offset;
    }

    virtual const char * getType() override { return "fukuro_common/Localization"; };
    virtual const char * getMD5() override { return "d25fba6248365fe1c093e492c489b9fd"; };

  };

}
#endif
