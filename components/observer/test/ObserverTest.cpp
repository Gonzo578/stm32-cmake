#include "ISubject.h"
#include <gmock/gmock.h>
#include "gtest/gtest.h"

using testing::Test;
using testing::Eq;
using testing::IsNull;
using testing::NotNull;
using testing::TypedEq;

namespace ObserverUnitTest {
    namespace testing {
	    class ObserverTest : public Test {
	    protected:
		    ObserverTest(){}
		    ~ObserverTest(){}
            
            Subject_t subject;
            Observer_t observer_1;
            Observer_t observer_2;
            Observer_t observer_3;

		    virtual void SetUp(){
                /*  Init subject with dummy values in order to simulate that
                    the subject might not be initialized by default */
                subject.pHead   = (Observer_t*)1234;
                subject.cnt     = 1;

                observer_1.p_next   = (Observer_t*)1234;
                observer_1.p_prev   = (Observer_t*)1234;
                observer_1.p_cb     = (Observer_cb_t)0;
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

        TEST_F(ObserverTest, ObserverIsNotInitializedBeforeCreation) {
		    EXPECT_THAT(observer_1.p_next,  NotNull());
            EXPECT_THAT(observer_1.p_prev,  NotNull());
            EXPECT_THAT(observer_1.p_cb,    IsNull());
	    }

        TEST_F(ObserverTest, ObserverIsInitializedAfterCreation) {
            OBS_CreateObserver(&observer_1, (Observer_cb_t)4321);
		    EXPECT_THAT(observer_1.p_next,  IsNull());
            EXPECT_THAT(observer_1.p_prev,  IsNull());
            EXPECT_THAT(observer_1.p_cb,    NotNull());
	    }

    }   // namespace testing
}   // namespace Observer
