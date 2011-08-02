require("lunatest")
require("luahapi")

function vector_verification(constructor, dimension)
	local args1 = {}
	local args2 = {}
	for i=1,dimension do
		table.insert(args1, 1)
		table.insert(args2, 2)
	end

	local u = constructor()
	assert_equal(constructor().dimension, dimension)
	assert_equal(constructor(unpack(args1)).dimension, dimension)
	assert_equal(constructor(unpack(args2)).dimension, dimension)
	assert_equal(constructor(), constructor())
	assert_equal(u, constructor())
	assert_equal(u, constructor())
	assert_not_equal(constructor(), constructor(unpack(args1)), "Default initialized vector and initialized vector shouldn't match")
	assert_not_equal(constructor(unpack(args1)), constructor(unpack(args2)), "differently-initialized vectors shouldn't match")
	assert_equal(constructor(unpack(args1)), constructor(unpack(args1)), "identically-initialized vectors should match")
	assert_equal(constructor(unpack(args2)), constructor(unpack(args2)), "identically-initialized vectors should match")
	--[[
	local v = constructor(unpack(args2))
	assert_equal(v, constructor(v), "copy-constructed vectors should match")
	]]
end

function vector_verification_with_length(constructor, dimension)
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
	assert_equal(constructor().length, 0)
	assert_equal(constructor().lengthSqr, 0)
	
	assert_equal(constructor(unpack(args1)).lengthSqr, lenSq1)
	assert_equal(constructor(unpack(args2)).lengthSqr, lenSq2)
	vector_verification(constructor, dimension)
end

function test_vec2()
	vector_verification_with_length(HAPI.Vec2, 2)
end

function test_vec3()
	vector_verification_with_length(HAPI.Vec3, 3)
end

function test_vec4()
	vector_verification(HAPI.Vec4, 4)
end


lunatest.run()
