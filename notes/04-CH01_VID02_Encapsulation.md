### **Encapsulation in Object-Oriented Programming (OOP)**

Encapsulation refers to the concept of keeping each unit in a system self-contained. In OOP, objects encapsulate their attributes and expose controlled access through functions (methods). This means external entities do not interact directly with an object's attributes but rather through predefined functions.

#### **The Shift from Global Variables to Encapsulation**

- In older languages like C, common variables were often shared across functions, sometimes globally.
- In modern OOP, each attribute is linked to a specific object, ensuring better organization and separation.
- For example, if a `Person` class has a `firstName` attribute, the system must first determine which object’s `firstName` is being accessed before performing any operation on it.

#### **Understanding Classes and Objects**

- A **class** is a **design template** or a **blueprint** used to create objects.
- An **object** is an actual instance of a class with real values assigned to its attributes.

##### **Example: Designing a House vs. Building a House**

- Suppose an architect designs a blueprint for a house, specifying its dimensions, entrances, and directions.
- This **blueprint represents a class**—it is just a design, not a real house.
- The actual house that gets built from the blueprint is an **object**, meaning an instance of the class.
- Many houses can be built using the same blueprint, just as multiple objects can be instantiated from the same class.

#### **Class Diagram Representation in UML**

- In UML diagrams, a class is typically divided into three sections:
  1. **Class Name** (usually written as a noun with a capital letter).
  2. **Attributes** (variables or properties).
  3. **Methods** (functions defining behavior).

##### **Example: Class `Person`**

```plaintext
-----------------------
|      Person        |  ← (Class Name)
-----------------------
| - name: String    |  ← (Private Attribute)
| - birthState: String |
-----------------------
| + getName(): String |  ← (Public Method)
| + setName(name: String) |
-----------------------
```

- The **minus sign (-)** before `name` and `birthState` means these attributes are **private**—they cannot be accessed directly outside the class.
- The **getter (`getName`)** and **setter (`setName`)** methods allow controlled access to these attributes.

#### **Objects and Instance-Specific Values**

- When creating an instance (`object1`) from the `Person` class, it inherits all attributes but stores specific values.
- For example, if `object1` is a `Person`, calling `setName("Ahmed")` will modify the `name` attribute only for `object1`, not for other objects.
- Each object has its **own separate data**, even if created from the same class.

### **Key Takeaways**

- **Encapsulation** ensures controlled access to data through methods, preventing direct modification of attributes.
- **Classes** serve as blueprints, while **objects** are actual instances with specific values.
- **UML diagrams** help visualize class structure, attributes, and behavior.
- **Instance-specific data** ensures each object maintains its own unique values while sharing a common design.
