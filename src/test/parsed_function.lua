require("lunatest")
require("luahapi")

function construction_test()
	assert_userdata(HAPI.ParsedFunction())
end

function setfunction_test()
	local func = HAPI.ParsedFunction()
	assert_true(func:setFunctionString("x * x"))
	assert_true(func:haveValidFunction())
	assert_equal(func:evaluate(5), 25)
end

function setfunction_with_param_test()
	local func = HAPI.ParsedFunction()
	assert_true(func:setFunctionString("y * y", "y"))
	assert_true(func:haveValidFunction())
	assert_equal(func:evaluate(5), 25)
end

lunatest.run()
