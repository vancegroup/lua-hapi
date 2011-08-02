require("lunatest")

function test_loads()
	require("luahapi")
	assert_table(HAPI)
end

lunatest.run()
