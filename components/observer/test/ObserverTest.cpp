#include "ISubject.h"
#include <gmock/gmock.h>
#include "gtest/gtest.h"
#include <cstdint>

using testing::Test;
using testing::Eq;
using testing::IsNull;
using testing::NotNull;
using testing::TypedEq;

namespace ObserverUnitTest {
    namespace testing {

        uint32_t Observer_1_CallCnt;
        uint32_t Observer_2_CallCnt;
        uint32_t Observer_3_CallCnt;
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
                Observer_1_CallCnt  = 0;
                Observer_2_CallCnt  = 0;
                Observer_3_CallCnt  = 0;
            }

		    virtual void TearDown(){}

            static void Observer1_CB(void) {
                Observer_1_CallCnt++;
            }

            static void Observer2_CB(void) {
                Observer_2_CallCnt++;
            }
            
            static void Observer3_CB(void) {
                Observer_3_CallCnt++;
            }
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

        TEST_F(ObserverTest, AttachSingleObserver) {
            OBS_CreateSubject(&subject);
            OBS_CreateObserver(&observer_1, (Observer_cb_t)Observer1_CB);
		    OBS_Attach(&subject, &observer_1);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(0));
	    }

        TEST_F(ObserverTest, AttachSingleObserverAndNotify) {
            OBS_CreateSubject(&subject);
            OBS_CreateObserver(&observer_1, (Observer_cb_t)Observer1_CB);
		    OBS_Attach(&subject, &observer_1);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(0));
            OBS_Notify(&subject);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(1));
            OBS_Notify(&subject);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(2));
	    }

        TEST_F(ObserverTest, AttachMultipleObservers) {
            OBS_CreateSubject(&subject);
            OBS_CreateObserver(&observer_1, (Observer_cb_t)Observer1_CB);
            OBS_CreateObserver(&observer_2, (Observer_cb_t)Observer2_CB);
            OBS_CreateObserver(&observer_3, (Observer_cb_t)Observer3_CB);
		    OBS_Attach(&subject, &observer_1);
            OBS_Attach(&subject, &observer_2);
            OBS_Attach(&subject, &observer_3);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(0));
            EXPECT_THAT(Observer_2_CallCnt,  Eq(0));
            EXPECT_THAT(Observer_3_CallCnt,  Eq(0));
	    }

        TEST_F(ObserverTest, AttachMultipleObserversAndNotify) {
            OBS_CreateSubject(&subject);
            OBS_CreateObserver(&observer_1, (Observer_cb_t)Observer1_CB);
            OBS_CreateObserver(&observer_2, (Observer_cb_t)Observer2_CB);
            OBS_CreateObserver(&observer_3, (Observer_cb_t)Observer3_CB);
		    OBS_Attach(&subject, &observer_1);
            OBS_Attach(&subject, &observer_2);
            OBS_Attach(&subject, &observer_3);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(0));
            EXPECT_THAT(Observer_2_CallCnt,  Eq(0));
            EXPECT_THAT(Observer_3_CallCnt,  Eq(0));
            OBS_Notify(&subject);
            EXPECT_THAT(Observer_1_CallCnt,  Eq(1));
            EXPECT_THAT(Observer_2_CallCnt,  Eq(1));
            EXPECT_THAT(Observer_3_CallCnt,  Eq(1));
	    }

    }   // namespace testing
}   // namespace Observer
