require("lunatest")
require("luahapi")

function test_class_names()
	names = class_names()
	assert_table(names)
	assert_not_equal(#names, 0)

	print("Class Names:")
	for _, v in ipairs(names) do
		print(v)
	end
end

trivially_constructible = {
	"AnyHapticsDevice"
}

for _, v in ipairs(trivially_constructible) do
	_G["test_class_info_" .. v] = function()
		local o = HAPI[v]()
		local info = class_info(o)
		assert_userdata(info)
		assert_string(info.name)
		print("Class:", info.name)

		assert_table(info.methods)
		print("Methods:", #(info.methods))
		for _, v in ipairs(info.methods) do
			print("-", v)
		end

		assert_table(info.attributes)
		print("Attributes:", #(info.attributes))
		for _, v in ipairs(info.attributes) do
			print("-", v)
		end
		print()
	end
end

lunatest.run()
