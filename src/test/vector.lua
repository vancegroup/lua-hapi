require("lunatest")
require("luahapi")


for dimension=2,4 do
	local name = "Vec" .. tostring(dimension)
	local constructor = HAPI[name]

	local args1 = {}
	local args2 = {}
	local lenSq1 = 0
	local lenSq2 = 0
	for i=1,dimension do
		lenSq1 = lenSq1 + 1 * 1
		table.insert(args1, 1)

		lenSq2 = lenSq2 + 2 * 2
		table.insert(args2, 2)
	end

	local u = constructor()
	local v = constructor(unpack(args1))
	local q = constructor(unpack(args2))

	_G[name .. "_dimension_test"] = function()
		assert_equal(constructor().dimension, dimension)
		assert_equal(constructor(unpack(args1)).dimension, dimension)
		assert_equal(constructor(unpack(args2)).dimension, dimension)
	end

	_G[name .. "_simple_equality_test"] = function()
		assert_not_equal(constructor(), constructor(unpack(args1)), "Default initialized vector and initialized vector shouldn't match")
		assert_not_equal(constructor(unpack(args1)), constructor(unpack(args2)), "differently-initialized vectors shouldn't match")

		assert_equal(u, constructor())
		assert_equal(constructor(), constructor())
		assert_equal(constructor(unpack(args1)), constructor(unpack(args1)), "identically-initialized vectors should match")
		assert_equal(constructor(unpack(args2)), constructor(unpack(args2)), "identically-initialized vectors should match")
	end

	_G[name .. "_copy_constructor_test"] = function()
		assert_equal(v, constructor(v), "copy-constructed vectors should match")
		local copy = constructor(q)
		assert_equal(q, copy)
		copy.x = -1
		assert_not_equal(q, copy)
	end

	_G[name .. "_tostring_test"] = function()
		assert_string(tostring(v))
	end

	_G[name .. "_plusminus_test"] = function()
		assert_equal(v + q, q + v)
		assert_equal((v + q) - q, v)
	end

	_G[name .. "_dotproduct_test"] = function()
		assert_number(v * q)
	end

	_G[name .. "_scale_test"] = function()
		assert_equal(v * 1, v)
	end

	if dimension < 4 then
		_G[name .. "_length_test"] = function()
			assert_equal(constructor().length, 0)
			assert_equal(constructor().lengthSqr, 0)

			assert_equal(constructor(unpack(args1)).lengthSqr, lenSq1)
			assert_equal(constructor(unpack(args2)).lengthSqr, lenSq2)
		end
	end
end

lunatest.run()
