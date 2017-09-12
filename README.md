# Brief solution description
Program was written in Visual studio 2017 (VS) as console application using C++.
Source codes whould be multiplatform.
VS solution consists of 2 project "ramp" (Actual solution) and "UnitTest".

## Input params
Program accepts only colours defined in decimal or hexadecimal format. It accepts only well defined params. So e.g. "0x33foo" or "bar42", "-1", "0xfffffffff" are not valid params.

Valid colours are e.g. "0", "0x0", "42", "0Xffff", 0xAaA.

## Naming conventions
In sources is used convetion m_<variable> name for member of static variables and I<class name> for interface name.

## Main Classes
**Error** - It ties error code and error message together. Has couple of supporting method. All error codes are described in ErrCode enum. And err message is asigned in Error constructor.
**ColourRGB565** - Represet RGB color in RGB565 format.
**ParamParser** - Parses command-line params.
**ColourRamp** - Calculates 4 colour ramp.
**IDisplay** - Is used in unit test and also as pure virtual base class of class Display. Purpose of this class is to create dependency injection in Unittest project.

## Unit test classes
**MocDisplay** - Represet moc (fake) class simulating original Display class. It is used for unit tests od class ColourRamp.
**TestParamParser** - Tests ParamParser class.
**TestColourRamp** - Tests ColourRamp class.

## Future improvements
 - Add unittest for ColourRGB565 class
 - Add more complex unitetests for ColourRamp.