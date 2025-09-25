
function testNullCheck()
    local str = nil
    -- bad
    print(#str)
    if str ~= nil then
        print("String is not nil")
    end
end

function anotherTest()
    local ptr = nil
    -- bad
    print(ptr.someProperty)
    if ptr ~= nil then
        print("Pointer is not nil")
    end
end

function invalidAccess()
    local arr = nil
    -- bad
    print(arr[1])
    if arr ~= nil then
        print("Array is not nil")
    end
end

function badAccess()
    local myObj = nil
    -- bad
    myObj:methodCall()
    if myObj ~= nil then
        print("MyObject is not nil")
    end
end


function testNullCheckGood()
    local str = nil
    if str ~= nil then
        -- good
        print(#str)
    end
end

function anotherTestGood()
    local ptr = nil
    if ptr ~= nil then
        -- good
        print(ptr.someProperty)
    end
end

function validAccess()
    local arr = nil
    if arr ~= nil then
        -- good
        print(arr[1])
    end
end

function goodAccess()
    local myObj = nil
    if myObj ~= nil then
        -- good
        myObj:methodCall()
    end
end

-- Method definition for testing
function MyObject:methodCall()
    print("Method called")
end