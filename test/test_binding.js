const yespower = require("../lib/binding.js");
const assert = require("assert");

assert(yespower, "The expected function is undefined");

function testBasic()
{
    var data = new Buffer.from("0000002009f42768de3cfb4e58fc56368c1477f87f60e248d7130df3fb8acd7f6208b83a72f90dd3ad8fe06c7f70d73f256f1e07185dcc217a58b9517c699226ac0297d2ad60ba61b62a021d9b7700f0", "hex");
    const result =  yespower(data);
    //console.log(result.toString("hex"));
    assert(result, new Buffer.from("9d90c21b5a0bb9566d2999c5d703d7327ee3ac97c020d387aa2dfd0700000000","hex"), "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");