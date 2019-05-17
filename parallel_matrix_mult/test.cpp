#include "pch.h"
#include "matrix.h"

class MatrixMult : public ::testing::Test
{
protected:
	void SetUp() override
	{
		m1 = Matrix(2, 3);
		m2 = Matrix(std::vector<std::vector<int>>(3, std::vector<int>(5, 3)));
		m12_result = Matrix(2, 5);

		m3 = Matrix(std::vector<std::vector<int>> { {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 }, { 13, 14, 15 }});
		m23_result = Matrix(std::vector<std::vector<int>>(3, std::vector<int>{105, 120, 135}));

		m4 = Matrix(std::vector<std::vector<int>>(512, std::vector<int>(512, 2)));
		m5 = Matrix(std::vector<std::vector<int>>(512, std::vector<int>(512, 2)));
		m45_result = Matrix(std::vector<std::vector<int>>(512, std::vector<int>(512, 2048)));
	}
	Matrix m1, m2, m3, m12_result, m23_result, m4, m5, m45_result;
};

TEST_F(MatrixMult, with_1_thread)
{
	ASSERT_EQ(m4* m5, m45_result);
}

TEST_F(MatrixMult, with_2_threads)
{
	ASSERT_EQ(m4.parallel_mult(m5, 2), m45_result);
}

TEST_F(MatrixMult, with_3_threads)
{
	ASSERT_EQ(m4.parallel_mult(m5, 3), m45_result);
}

TEST_F(MatrixMult, with_4_threads)
{
	ASSERT_EQ(m4.parallel_mult(m5, 4), m45_result);
}

TEST_F(MatrixMult, with_5_threads)
{
	ASSERT_EQ(m4.parallel_mult(m5, 5), m45_result);
}
//TEST_F(MatrixMult, NotSuitableSizes)
//{
//	ASSERT_THROW(m1 * m3, std::length_error);
//}

int main(int argc, char *argv[])
{
	::testing::FLAGS_gtest_output = "xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}