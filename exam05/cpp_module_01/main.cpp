#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

void        test_leak()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);

}

int main()
{
    test_leak();
    system("leaks a.out | grep bytes");
    return 0;
}