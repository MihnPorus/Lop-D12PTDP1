#pragma once

#include "Nguoi.h"
#include "Diem.h"

class ThiSinh :  public Diem , public virtual Nguoi, virtual VaoRaChuan
{
public:
	void Nhap() const override;
	void HienThi() const override;
};

