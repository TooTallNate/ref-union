
var assert = require('assert')
  , ref = require('ref')
  , Union = require('../')
  , bindings = require('./build/Release/native_tests')

describe('Union', function () {

  afterEach(gc)

  it('should be a function', function () {
    assert.equal('function', typeof Union)
  })

})
