#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    std::vector<ASpell*>::iterator it = _spells.begin();

    for (; it != _spells.end(); ++it)
        delete (*it);
}

void                        SpellBook::learnSpell(ASpell* spell)
{
    std::vector<ASpell*>::iterator it = _spells.begin();

    for (; it != _spells.end(); ++it)
        if ((*it)->getName() == spell->getName())
            return ;
    _spells.push_back(spell->clone());
}

void                        SpellBook::forgetSpell(const std::string& spell_name)
{
    std::vector<ASpell*>::iterator it = _spells.begin();

    for (; it != _spells.end(); ++it)
        if ((*it)->getName() == spell_name)
        {
            delete (*it);
            _spells.erase(it);
            return ;
        }
}

ASpell*                        SpellBook::createSpell(const std::string& spell_name)
{
    std::vector<ASpell*>::iterator it = _spells.begin();

    for (; it != _spells.end(); ++it)
        if ((*it)->getName() == spell_name)
            return (*it);
    return NULL;
}