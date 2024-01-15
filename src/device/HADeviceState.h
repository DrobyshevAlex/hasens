#pragma once

class HADeviceState
{
public:
  float getT()
  {
    return _t;
  }

  void setT(float v)
  {
    _t = v;
  }

  float getH()
  {
    return _h;
  }

  void setH(float v)
  {
    _h = v;
  }

  bool operator==(HADeviceState &o)
  {
    return _t == o._t && _h == o._h;
  }

  bool operator!=(HADeviceState &other)
  {
    return !(*this == other);
  }

private:
  float _t = 0.0;
  float _h = 0.0;
};
