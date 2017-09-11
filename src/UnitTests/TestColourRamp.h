#ifndef TEST_COLOUR_RAMP_H
#define TEST_COLOUR_RAMP_H

class TestColourRamp
{
public:
	static void TestCouldNotConnectToDisplay();
	static void TestToSmallDisplay();
	static void TestBasicRamps();

private:
	static const char* m_fakeDisplayName;
};

#endif //!TEST_COLOUR_RAMP_H
