#pragma once
#include <string>
#include <cstdint>

enum eOperandType
{
    t_int8,
    t_int16,
    t_int32,
    t_float,
    t_double
};

class IOperand {
protected:
    eOperandType type;
public:
    virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0; // Type of the instance
    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
    virtual std::string const & toString( void ) const = 0; // String representation of the instance

    virtual ~IOperand( void ) {}
};

union U_OperandType
{
    std::int32_t int32;
    std::uint16_t int16;
    std::uint8_t int8;
};

template <typename T>
class Operand : public IOperand 
{
private:
    U_OperandType value;
public:
    int getPrecision( void ) const override; // Precision of the type of the instance
    eOperandType getType( void ) const override; // Type of the instance
    void setType(eOperandType _type);

    IOperand const * operator+(  IOperand const & rhs ) const override;
    IOperand const * operator-(  IOperand const & rhs ) const override;
    IOperand const * operator*( IOperand const & rhs ) const override; // Product
    IOperand const * operator/( IOperand const & rhs ) const override; // Quotient
    IOperand const * operator%( IOperand const & rhs ) const override; // Modulo
    std::string const & toString( void ) const override; // String representation of the instance

    U_OperandType getValue();
    void setValue(U_OperandType _value);
};

