#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;
    std::string contact;
public:
    User(const std::string& name, const std::string& contact);
    virtual void displayRole() = 0;
    std::string getName() const;
    std::string getContact() const;
    virtual ~User() = default;
};

#endif // USER_H