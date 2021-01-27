#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <string>
# include <vector>
# include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
    std::vector<ATarget*>      _targets;

    TargetGenerator(const TargetGenerator& other);
    TargetGenerator&        operator=(const TargetGenerator& other);
    
  public:
    TargetGenerator();
    ~TargetGenerator();

    void                    learnTargetType(ATarget* target);
    void                    forgetTargetType(const std::string& target);
    ATarget*                createTarget(const std::string& target);
};


#endif