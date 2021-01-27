#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class ATarget;
class ASpell;
class SpellBook;

class Warlock
{
    std::string               _name;
    std::string               _title;

    SpellBook                 _spellBook;

    Warlock();
    Warlock(const Warlock& other);
    Warlock&        operator=(const Warlock& other);
    
  public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();
    const std::string&      getName() const;
    const std::string&      getTitle() const;
    void                    setTitle(const std::string& title);
    void                    introduce() const;
    void                    learnSpell(ASpell* spell);
    void                    forgetSpell(const std::string spell_name);
    void                    launchSpell(const std::string spell_name, const ATarget& target);
};


#endif
