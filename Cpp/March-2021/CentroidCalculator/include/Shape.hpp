
#pragma once

#include <string>
#include <unordered_map>
#include <any>

#include "MathLib.hpp"
#include "Typedefs.hpp"

struct Property
{
  std::string type;
  std::any value;

  template <class T>
  T &get()
  {
    return std::any_cast<T>(value);
  }
};

using Key = std::string;

class Shape
{
public:
  virtual ~Shape()
  {
    // Virtual destructor
  }

  Property &operator[](const Key &key)
  {
    return properties[key];
  }
  std::unordered_map<Key, Property> &getAllProperties()
  {
    return this->properties;
  }
  void removeProperty(const Key &key)
  {
    properties.erase(key);
  }
  template <class T>
  void setProperty(const Key &key, const T &property)
  {
    properties[key] = property;
  }

  template <class T>
  void setPropertyValue(const Key &key, const T &value)
  {
    properties[key].value = value;
  }

  template <class PropertyType>
  PropertyType &getPropertyValue(const Key &key)
  {
    return std::any_cast<PropertyType &>(properties[key].value);
  }

  template <class BehaviorType>
  BehaviorType &getBehavior(const Key &key)
  {
    return std::any_cast<BehaviorType &>(properties[key].value);
  }

  std::string getShapeType()
  {
    return properties["shapeType"].get<std::string &>();
  }
  void setShapeType(const std::string &shapeType)
  {
    this->setProperty(
        "shapeType",
        Property{.type = "shapeDetails", .value = shapeType});
  }

  std::unordered_map<Key, Property> properties;
};