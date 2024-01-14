#include "EntityRegister.h"

// Example "Entity" class
class Entity {
  public:
    std::string name{"NAME"};

    Entity(std::string name_in) {name = name_in; print_memory_location();}

    void print_memory_location() {std::cout << name << ": " << this << "\n"; return;}
};

// Example program to demonstrate processor
int main(int argc, char** argv) {
  
  // Create three "Entities"
  Entity A("EntityA");
  Entity B("EntityB");
  Entity C("EntityC");

  // Create processor and ER entities
  EntityRegister ER;
  ER.register_entity(A);
  ER.register_entity(B);
  ER.register_entity(C);

  // Print registry
  ER.print_registry(); 

  // Check if Entity B is in registry
  if (ER.check_in_registry(B))
    std::cout << B.name << " is in registry\n";
  else
    std::cout << B.name << " is not in registry\n";

  // Remove Entity B from registry
  ER.unregister_entity(B);

  // Check if Entity B is in registry
  if (ER.check_in_registry(B))
    std::cout << B.name << " is in registry\n";
  else
    std::cout << B.name << " is not in registry\n";

  // Print registry
  ER.print_registry();

  return 0;
}