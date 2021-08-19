#include "ISubject.h"
#include <gmock/gmock.h>
#include "gtest/gtest.h"

using testing::Test;
using ::testing::Eq;

namespace Observer {
    namespace testing {
	    class ObserverTest : public Test {
	    protected:
		    ObserverTest(){}
		    ~ObserverTest(){}
            
            Subject_t subject;

		    virtual void SetUp(){}
		    virtual void TearDown(){}
	    };

        TEST_F(ObserverTest, constructor_foo) {
		    EXPECT_THAT(true, Eq(true));
	    }

        TEST_F(ObserverTest, constructor_bar) {
		    EXPECT_THAT(true, Eq(false));
	    }

    }   // namespace testing
}   // namespace Observer
