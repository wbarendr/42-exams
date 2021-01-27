#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <string>
# include <vector>
# include "ASpell.hpp"

class ASpell;

class SpellBook
{
    std::vector<ASpell*>      _spells;

    SpellBook(const SpellBook& other);
    SpellBook&        operator=(const SpellBook& other);
    
  public:
    SpellBook();
    ~SpellBook();

    void                    learnSpell(ASpell* spell);
    void                    forgetSpell(const std::string& spell_name);
    ASpell*                 createSpell(const std::string& spell_name);
};


#endif
