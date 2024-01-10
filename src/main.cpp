#include <vector>
#include <string>
#include <iostream>

class Entity {
  public:
    std::string name{"NAME"};
    int value{0};
    void print_memory_location() {std::cout << name << ": " << this << "\n"; return;}
    void print_value() {std::cout << "Value of " << name << ": " << value << "\n";}
    Entity(std::string name_in) {name = name_in; print_memory_location();}
};

class EntityProcessor {
  public:
    std::vector<Entity*> Entities;
    void register_entity(Entity& entity);
    void unregister_entity(Entity& entity);
    void print_entities_locations();
    void modify_entities();
};

void EntityProcessor::register_entity(Entity& entity) {
  Entity* ptr = &entity;
  Entities.push_back(ptr);
  return;
}

void EntityProcessor::unregister_entity(Entity& entity) {
  return;
}

void EntityProcessor::print_entities_locations() {
  std::cout << "\nEntity Processor Registry:\n";
  for (int idx = 0; idx < Entities.size(); idx++) {
    Entities[idx]->print_memory_location();
  }
  std::cout << "\n";
}

void EntityProcessor::modify_entities() {
  for (int idx = 0; idx < Entities.size(); idx++) {
    Entities[idx]->value = rand() % 100 + 1;
    std::cout << "New value for " << Entities[idx]->name << ": " << Entities[idx]->value << "\n"; 
  }

}

int main(int argc, char** argv) {

  std::cout << "\n";
  
  Entity A("EntityA");
  Entity B("EntityB");
  Entity C("EntityC");

  EntityProcessor EP;
  EP.register_entity(A);
  EP.register_entity(B);
  EP.register_entity(C);

  EP.print_entities_locations(); 

  return 0;
}