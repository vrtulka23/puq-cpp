#include "lists.h"

namespace puq {

  const UnitListType* UnitSystem::UnitList = &UnitSystem::SI;
  
  std::stack<const UnitListType *> UnitSystem::systemStack;
  
  UnitSystem::UnitSystem(const UnitListType& st): closed(false) {
    systemStack.push(UnitList);
    UnitList = &st;
  }
  
  UnitSystem::UnitSystem(const UnitListType* st): closed(false) {
    systemStack.push(UnitList);
    UnitList = st;
  }
  
  UnitSystem::~UnitSystem() {
    if (!closed)
      close();
  }

  void UnitSystem::change(const UnitListType* st) {
    UnitList = systemStack.top();
    systemStack.pop();
    systemStack.push(UnitList);
    UnitList = st;
  }
  
  void UnitSystem::close() {
    UnitList = systemStack.top();
    systemStack.pop();
    closed = true;
  }

}
