// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// Can we add a single values to the collection?
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 1);
}

// Can we add multiple values to our collection?
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    add_entries(5);

    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeIsGreaterThanOrEqualTo){

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    ASSERT_TRUE(collection->max_size() >= collection->size()); //Verify that max_size is greater than or equal to the size of collection

    add_entries(1); //Add 1 entry

    ASSERT_TRUE(collection->max_size() >= collection->size()); //Verify that max_size is greater than or equal to the size of collection

    add_entries(4); //Add 4 entries

    ASSERT_EQ(collection->size(), 5); //Verify that there are 5 entries total

    ASSERT_TRUE(collection->max_size() >= collection->size()); //Verify that max_size is greater than or equal to the size of collection

    add_entries(5); //Add 5 entries

    ASSERT_EQ(collection->size(), 10); //Verify that there are 10 entries total

    ASSERT_TRUE(collection->max_size() >= collection->size()); //Verify that max_size is greater than or equal to the size of collection


}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityIsGreaterThanOrEqualTo) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    ASSERT_TRUE(collection->capacity() >= collection->size()); //Verify that capacity is greater than or equal to the size of collection

    add_entries(1); //Add 1 entry

    ASSERT_TRUE(collection->capacity() >= collection->size()); //Verify that capacity is greater than or equal to the size of collection

    add_entries(4); //Add 4 entries

    ASSERT_EQ(collection->size(), 5); //Verify that there are 5 entries total

    ASSERT_TRUE(collection->capacity() >= collection->size()); //Verify that capacity is greater than or equal to the size of collection

    add_entries(5); //Add 5 entries

    ASSERT_EQ(collection->size(), 10); //Verify that there are 10 entries total

    ASSERT_TRUE(collection->capacity() >= collection->size()); //Verify that capacity is greater than or equal to the size of collection


}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizeIncreasesCollection) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    collection->resize(5); //Resize collection

    ASSERT_EQ(collection->size(), 5); //verify that size increased
}

// Can we decrease the collection size using the resize function?
TEST_F(CollectionTest, ResizeDecreasesCollection) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    add_entries(7); //Add 7 entries

    ASSERT_EQ(collection->size(), 7); //verify new size

    collection->resize(3); //Resize collection

    ASSERT_EQ(collection->size(), 3); //verify that size decreased
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizeEmptiesCollection) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    add_entries(7); //Add 7 entries

    ASSERT_EQ(collection->size(), 7); //verify new size

    collection->resize(0); //Resize collection

    ASSERT_TRUE(collection->empty()); //verify that collection is empty
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearEmptiesCollection) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    add_entries(7); //Add 7 entries

    ASSERT_EQ(collection->size(), 7); //verify new size

    collection->clear(); //Clear collection

    ASSERT_TRUE(collection->empty()); //verify that collection is empty
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseEmptiesCollection) {

    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    add_entries(7); //Add 7 entries

    ASSERT_EQ(collection->size(), 7); //verify new size

    collection->erase(collection->begin(), collection->end()); //Erase collection

    ASSERT_TRUE(collection->empty()); //verify that collection is empty
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveincreasesCapacityNotSize) {
    collection->clear(); // Empty collection
    ASSERT_TRUE(collection->empty()); //Verify that the collection is empty

    ASSERT_TRUE(collection->size() == 0 && collection->capacity() == 0); //Verify that capacity and size are both 0

    collection->reserve(5); //Allocate memory for 5 elements without increasing size

    ASSERT_TRUE(collection->size() == 0 && collection->capacity() == 5); //Verify that capacity has increased and size has not

}

// TODO: Does calling an out of range element throw the proper exception?
// NOTE: This is a negative test
TEST_F(CollectionTest, OutOfRangeExceptionTest) {
    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify collection is empty

    EXPECT_THROW(collection->at(10), std::exception); //Verify that range error is thrown when invoking out of range element
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

TEST_F(CollectionTest, ShrinkToFitReducesCapacity) {
    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify empty collection

    collection->reserve(20);

    ASSERT_TRUE(collection->size() < collection->capacity()); //Verify that the size is less than the capacity

    collection->shrink_to_fit();

    ASSERT_EQ(collection->size(), collection->capacity());

}

TEST_F(CollectionTest, cannotIterateBeyondSize) {
    
    collection->clear(); //Empty collection
    ASSERT_TRUE(collection->empty()); //Verify empty collection

    add_entries(10); //add 10 entries

    EXPECT_THROW(for (int i = 0; i < 20; ++i) { collection->at(i); }, std::exception);
}