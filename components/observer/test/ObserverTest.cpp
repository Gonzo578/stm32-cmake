#include "ISubject.h"
#include <gmock/gmock.h>
#include "gtest/gtest.h"

using testing::Test;
using ::testing::Eq;
using testing::IsNull;
using testing::NotNull;

namespace Observer {
    namespace testing {
	    class ObserverTest : public Test {
	    protected:
		    ObserverTest(){}
		    ~ObserverTest(){}
            
            Subject_t subject;

		    virtual void SetUp(){
                subject.pHead   = (Observer_t*)1234;
                subject.cnt     = 1;
            }

		    virtual void TearDown(){}
	    };

        TEST_F(ObserverTest, SubjectIsNotInitializedBeforeCreation) {
		    EXPECT_THAT(subject.pHead, NotNull());
            EXPECT_THAT(subject.cnt, Eq(1));
	    }

        TEST_F(ObserverTest, SubjectIsInitializedAfterCreation) {
            OBS_CreateSubject(&subject);
		    EXPECT_THAT(subject.pHead, IsNull());
            EXPECT_THAT(subject.cnt, Eq(0));
	    }

    }   // namespace testing
}   // namespace Observer
